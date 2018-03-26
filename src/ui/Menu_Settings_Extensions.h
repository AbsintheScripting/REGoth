#pragma once
#include "Menu.h"

namespace UI
{
	class Menu_Settings_Extensions : public Menu
	{
	public:
		Menu_Settings_Extensions(Engine::BaseEngine& e);
		~Menu_Settings_Extensions();

		/**
		* Creates an instance of this class and appends it to the root UI-View
		* @return Instance of the class. Don't forget to delete!
		*/
		static Menu_Settings_Extensions* create(Engine::BaseEngine& e);

		/**
		* To be called when one of the given actions were triggered
		* @param action Input action
		*/
		bool onInputAction(Engine::ActionType action) override;

		void onCustomAction(const std::string& action) override;

	private:
		/**
		* Performs the select-action on the given item
		* @param item Item to perform the action on
		*/
		void performSelectAction(Daedalus::GameState::MenuItemHandle item) override;

		bool m_isWaitingForSettingInput = false;
	};
}
