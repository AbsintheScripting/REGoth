#include "Menu_Settings_Graphics.h"
#include "MenuItem.h"
#include "Menu_Settings.h"
#include "Hud.h"

using namespace UI;

Menu_Settings_Graphics::Menu_Settings_Graphics(Engine::BaseEngine& e)
	: Menu(e)
{
}

Menu_Settings_Graphics::~Menu_Settings_Graphics()
{
}

Menu_Settings_Graphics* Menu_Settings_Graphics::create(Engine::BaseEngine& e)
{
	Menu_Settings_Graphics* s = new Menu_Settings_Graphics(e);
	s->initializeInstance("MENU_OPT_GRAPHICS");

	return s;
}

void Menu_Settings_Graphics::performSelectAction(Daedalus::GameState::MenuItemHandle item)
{
	MenuItem* iData = m_Items[item];

	using namespace Daedalus::GEngineClasses::MenuConstants;

	Menu::performSelectAction(item);
}

bool Menu_Settings_Graphics::onInputAction(Engine::ActionType action)
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

void Menu_Settings_Graphics::onCustomAction(const std::string& action)
{
	Utils::RecursiveStopWatch excludeFrameTime(m_Engine.m_ExcludedFrameTime);
	/*
	if (action == "MENU_OPT_GAME") // Game Settings
	{
	LogInfo() << "HUD: MENUITEM_OPT_GAME";
	getHud().pushMenu<Menu_Load>();
	}
	*/
}

