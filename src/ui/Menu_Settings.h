/* 
 * Author: Migos (@AbsintheScripting)
 */

#pragma once
#include "Menu.h"

namespace UI
{
    class Menu_Settings : public Menu
    {
    public:
        Menu_Settings(Engine::BaseEngine& e);
        ~Menu_Settings();

        /**
         * Creates an instance of this class and appends it to the root UI-View
         * @return Instance of the class. Don't forget to delete!
         */
        static Menu_Settings* create(Engine::BaseEngine& e);

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
    
    class Menu_Settings_Audio : public Menu_Settings {
    public:
        Menu_Settings_Audio(Engine::BaseEngine& e);
	~Menu_Settings_Audio();
        /**
        * Creates an instance of this class and appends it to the root UI-View
        * @return Instance of the class. Don't forget to delete!
        */
        static Menu_Settings_Audio* create(Engine::BaseEngine& e);
    };
    
    class Menu_Settings_Controls : public Menu_Settings {
    public:
        Menu_Settings_Controls(Engine::BaseEngine& e);
	~Menu_Settings_Controls();
        /**
        * Creates an instance of this class and appends it to the root UI-View
        * @return Instance of the class. Don't forget to delete!
        */
        static Menu_Settings_Controls* create(Engine::BaseEngine& e);
    };
    
    class Menu_Settings_Extensions : public Menu_Settings {
    public:
        Menu_Settings_Extensions(Engine::BaseEngine& e);
	~Menu_Settings_Extensions();
        /**
        * Creates an instance of this class and appends it to the root UI-View
        * @return Instance of the class. Don't forget to delete!
        */
        static Menu_Settings_Extensions* create(Engine::BaseEngine& e);
    };
    
    class Menu_Settings_Game : public Menu_Settings {
    public:
        Menu_Settings_Game(Engine::BaseEngine& e);
	~Menu_Settings_Game();
        /**
        * Creates an instance of this class and appends it to the root UI-View
        * @return Instance of the class. Don't forget to delete!
        */
        static Menu_Settings_Game* create(Engine::BaseEngine& e);
    };
    
    class Menu_Settings_Graphics : public Menu_Settings {
    public:
        Menu_Settings_Graphics(Engine::BaseEngine& e);
	~Menu_Settings_Graphics();
        /**
        * Creates an instance of this class and appends it to the root UI-View
        * @return Instance of the class. Don't forget to delete!
        */
        static Menu_Settings_Graphics* create(Engine::BaseEngine& e);
    };
    
    class Menu_Settings_Video : public Menu_Settings {
    public:
        Menu_Settings_Video(Engine::BaseEngine& e);
	~Menu_Settings_Video();
        /**
        * Creates an instance of this class and appends it to the root UI-View
        * @return Instance of the class. Don't forget to delete!
        */
        static Menu_Settings_Video* create(Engine::BaseEngine& e);
    };
}
