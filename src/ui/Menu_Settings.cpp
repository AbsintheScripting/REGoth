/* 
 * Author: Migos (@AbsintheScripting)
 */

#include "Menu_Settings.h"
#include "Hud.h"
#include "MenuItem.h"
#include "Menu_Main.h"

using namespace UI;

Menu_Settings::Menu_Settings(Engine::BaseEngine& e)
    : Menu(e)
{
}

Menu_Settings::~Menu_Settings()
{
}

Menu_Settings* Menu_Settings::create(Engine::BaseEngine& e)
{
    Menu_Settings* s = new Menu_Settings(e);
    s->initializeInstance("MENU_OPTIONS");

    return s;
}

void Menu_Settings::performSelectAction(Daedalus::GameState::MenuItemHandle item)
{
	MenuItem* iData = m_Items[item];

	using namespace Daedalus::GEngineClasses::MenuConstants;

	Menu::performSelectAction(item);
}

bool Menu_Settings::onInputAction(Engine::ActionType action)
{
	using Engine::ActionType;

	if (!m_isWaitingForSettingInput)
		return Menu::onInputAction(action);
	else
	{
		switch (action)
		{
		case ActionType::UI_Confirm:
			if (!m_SelectableItems.empty())
				performSelectAction(m_SelectableItems[m_SelectedItem]);
			break;
		case ActionType::UI_Close:
			m_isWaitingForSettingInput = false;
			break;
		default:
			break;
		}
	}
	return false;
}

void Menu_Settings::onCustomAction(const std::string& action)
{
	Utils::RecursiveStopWatch excludeFrameTime(m_Engine.m_ExcludedFrameTime);
	if (action == "MENU_OPT_GAME") // Game Settings
	{
		getHud().pushMenu<Menu_Settings_Game>();
	}
	else if (action == "MENU_OPT_GRAPHICS")
	{
		getHud().pushMenu<Menu_Settings_Graphics>();
	}
	else if (action == "MENU_OPT_VIDEO")
	{
		getHud().pushMenu<Menu_Settings_Video>();
	}
	else if (action == "MENU_OPT_AUDIO")
	{
		getHud().pushMenu<Menu_Settings_Audio>();
	}
	else if (action == "MENU_OPT_CONTROLS")
	{
		getHud().pushMenu<Menu_Settings_Controls>();
	}
	else if (action == "MENU_OPT_EXT")
	{
		getHud().pushMenu<Menu_Settings_Extensions>();
	}
}

