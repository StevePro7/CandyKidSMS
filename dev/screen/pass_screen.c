#include "pass_screen.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"

void screen_pass_screen_load()
{
	engine_font_manager_draw_text( "PASS SCREEN!!", 2, 10 );
}

void screen_pass_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_pass;
}
