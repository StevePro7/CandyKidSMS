#include "splash_screen.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"

#define MY_TEXT "HELLO SPLASH SCREEN"

void screen_splash_screen_load()
{
	engine_font_manager_draw_text( MY_TEXT, 2, 0 );
}

void screen_splash_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_splash;
}