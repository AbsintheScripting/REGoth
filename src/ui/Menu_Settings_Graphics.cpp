/* 
 * Author: Migos (@AbsintheScripting)
 */

#include "Menu_Settings.h"

using namespace UI;

Menu_Settings_Graphics::Menu_Settings_Graphics(Engine::BaseEngine& e)
	: Menu_Settings(e)
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
