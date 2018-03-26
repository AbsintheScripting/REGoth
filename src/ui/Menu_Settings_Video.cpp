#include "Menu_Settings_Video.h"
#include "MenuItem.h"
#include "Menu_Settings.h"
#include "Hud.h"

using namespace UI;

Menu_Settings_Video::Menu_Settings_Video(Engine::BaseEngine& e)
	: Menu(e)
{
}

Menu_Settings_Video::~Menu_Settings_Video()
{
}

Menu_Settings_Video* Menu_Settings_Video::create(Engine::BaseEngine& e)
{
	Menu_Settings_Video* s = new Menu_Settings_Video(e);
	s->initializeInstance("MENU_OPT_VIDEO");

	return s;
}

void Menu_Settings_Video::performSelectAction(Daedalus::GameState::MenuItemHandle item)
{
	MenuItem* iData = m_Items[item];

	using namespace Daedalus::GEngineClasses::MenuConstants;

	Menu::performSelectAction(item);
}

bool Menu_Settings_Video::onInputAction(Engine::ActionType action)
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

void Menu_Settings_Video::onCustomAction(const std::string& action)
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
