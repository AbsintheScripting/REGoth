/* 
 * Author: Migos (@AbsintheScripting)
 */

#include "Menu_Settings.h"

using namespace UI;

Menu_Settings_Game::Menu_Settings_Game(Engine::BaseEngine& e)
	: Menu_Settings(e)
{
}

Menu_Settings_Game::~Menu_Settings_Game()
{
}

Menu_Settings_Game* Menu_Settings_Game::create(Engine::BaseEngine& e)
{
	Menu_Settings_Game* s = new Menu_Settings_Game(e);
	s->initializeInstance("MENU_OPT_GAME");

	return s;
}
