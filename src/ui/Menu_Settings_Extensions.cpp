/* 
 * Author: Migos (@AbsintheScripting)
 */

#include "Menu_Settings.h"

using namespace UI;

Menu_Settings_Extensions::Menu_Settings_Extensions(Engine::BaseEngine& e)
	: Menu_Settings(e)
{
}

Menu_Settings_Extensions::~Menu_Settings_Extensions()
{
}

Menu_Settings_Extensions* Menu_Settings_Extensions::create(Engine::BaseEngine& e)
{
	Menu_Settings_Extensions* s = new Menu_Settings_Extensions(e);
	s->initializeInstance("MENU_OPT_EXT");

	return s;
}
