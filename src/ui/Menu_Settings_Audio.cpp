/* 
 * Author: Migos (@AbsintheScripting)
 */

#include "Menu_Settings.h"

using namespace UI;

Menu_Settings_Audio::Menu_Settings_Audio(Engine::BaseEngine& e)
	: Menu_Settings(e)
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

