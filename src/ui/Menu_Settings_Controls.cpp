/* 
 * Author: Migos (@AbsintheScripting)
 */

#include "Menu_Settings.h"

using namespace UI;

Menu_Settings_Controls::Menu_Settings_Controls(Engine::BaseEngine& e)
	: Menu_Settings(e)
{
}

Menu_Settings_Controls::~Menu_Settings_Controls()
{
}

Menu_Settings_Controls* Menu_Settings_Controls::create(Engine::BaseEngine& e)
{
	Menu_Settings_Controls* s = new Menu_Settings_Controls(e);
	s->initializeInstance("MENU_OPT_CONTROLS");

	return s;
}
