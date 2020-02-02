#include "pass_screen.h"
#include "..\engine\enum_manager.h"

void screen_pass_screen_load()
{
}

void screen_pass_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_pass;
}
