/* 
 * Author: Migos (@AbsintheScripting)
 */

#include "Menu_Settings.h"

using namespace UI;

Menu_Settings_Video::Menu_Settings_Video(Engine::BaseEngine& e)
	: Menu_Settings(e)
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
