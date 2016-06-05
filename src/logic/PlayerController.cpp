//
// Created by andre on 02.06.16.
//

#include "PlayerController.h"
#include <engine/Waynet.h>
#include <components/Entities.h>
#include <engine/World.h>
#include <debugdraw/debugdraw.h>
#include <render/WorldRender.h>

Logic::PlayerController::PlayerController(World::WorldInstance& world,
                                          Handle::EntityHandle entity,
                                          Daedalus::GameState::NpcHandle scriptInstance)
        : Controller(world, entity)
{
    m_RoutineState.routineTarget = static_cast<size_t>(-1);
    m_RoutineState.routineActive = false;

    m_AIState.closestWaypoint = 0;
    m_MoveState.currentPathPerc = 0;
    m_NPCProperties.moveSpeed = 10.0f;

    m_ScriptState.npcHandle = scriptInstance;
}

void Logic::PlayerController::onUpdate(float deltaTime)
{
    // Do waypoint-actions
    if (travelPath(deltaTime))
    {
        if (m_RoutineState.routineActive)
            continueRoutine();
    }
}

void Logic::PlayerController::continueRoutine()
{
    if(m_RoutineState.routineWaypoints.empty())
        return;

    // Start next route
    if (m_RoutineState.routineTarget == static_cast<size_t>(-1))
        m_RoutineState.routineTarget = 0; // Start routing. Could let the integer overflow do this, but this is better.
    else
        m_RoutineState.routineTarget++;

    // Start over, if done
    if (m_RoutineState.routineTarget + 1 >= m_RoutineState.routineWaypoints.size())
        m_RoutineState.routineTarget = 0;

    gotoWaypoint(m_RoutineState.routineWaypoints[m_RoutineState.routineTarget]);
}

void Logic::PlayerController::teleportToWaypoint(size_t wp)
{
    m_AIState.closestWaypoint = wp;

    // FIXME: Don't ignore wp-direction
    setEntityTransform(Math::Matrix::CreateTranslation(m_World.getWaynet().waypoints[wp].position));
}

void Logic::PlayerController::gotoWaypoint(size_t wp)
{
    if(wp == m_AIState.targetWaypoint)
        return;

    m_AIState.targetWaypoint = wp;

    // Route is most likely outdated, make a new one
    rebuildRoute();
}

void Logic::PlayerController::rebuildRoute()
{
    m_MoveState.currentPath = World::Waynet::findWay(m_World.getWaynet(),
                                                     m_AIState.closestWaypoint,
                                                     m_AIState.targetWaypoint);

    m_MoveState.currentPathPerc = 0.0f;
    m_MoveState.currentRouteLength = World::Waynet::getPathLength(m_World.getWaynet(), m_MoveState.currentPath);
}

bool Logic::PlayerController::travelPath(float deltaTime)
{
    if (m_MoveState.currentPath.empty())
        return true;

    // Frame update...
    m_MoveState.currentPathPerc = std::min(1.0f, m_MoveState.currentPathPerc
                                                 + deltaTime
                                                   * (m_NPCProperties.moveSpeed / m_MoveState.currentRouteLength));

    // Get new position
    Math::float3 position = World::Waynet::interpolatePositionOnPath(m_World.getWaynet(),
                                                                     m_MoveState.currentPath,
                                                                     m_MoveState.currentPathPerc);

    // TODO: Merge this with the interpolate-call!
    size_t cwp = World::Waynet::getWaypointOnPath(m_World.getWaynet(),
                                                  m_MoveState.currentPath,
                                                  m_MoveState.currentPathPerc);

    if(cwp != static_cast<size_t>(-1))
        m_AIState.closestWaypoint = m_MoveState.currentPath[cwp];

    // FIXME: This should be taken care of by the physics engine
    // FIXME: Direction is ignored
    setEntityTransform(Math::Matrix::CreateTranslation(position));

    if (m_MoveState.currentPathPerc >= 1.0f) // == would be sufficient here, but why not?
        return true;

    return false;
}

void Logic::PlayerController::onDebugDraw()
{
    if (!m_MoveState.currentPath.empty())
    {
        Render::debugDrawPath(m_World.getWaynet(), m_MoveState.currentPath);
    }
}