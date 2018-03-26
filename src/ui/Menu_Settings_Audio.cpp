#include "Menu_Settings_Audio.h"
#include "MenuItem.h"
#include "Menu_Settings.h"
#include "Hud.h"

using namespace UI;

Menu_Settings_Audio::Menu_Settings_Audio(Engine::BaseEngine& e)
	: Menu(e)
{
}

Menu_Settings_Audio::~Menu_Settings_Audio()
{
}

Menu_Settings_Audio* Menu_Settings_Audio::create(Engine::BaseEngine& e)
{
	Menu_Settings_Audio* s = new Menu_Settings_Audio(e);
	s->initializeInstance("MENU_OPT_AUDIO");

	return s;
}

void Menu_Settings_Audio::performSelectAction(Daedalus::GameState::MenuItemHandle item)
{
	MenuItem* iData = m_Items[item];

	using namespace Daedalus::GEngineClasses::MenuConstants;

	Menu::performSelectAction(item);
}

bool Menu_Settings_Audio::onInputAction(Engine::ActionType action)
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

void Menu_Settings_Audio::onCustomAction(const std::string& action)
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

