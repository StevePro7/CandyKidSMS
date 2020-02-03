#include "dead_screen.h"
#include "..\engine\audio_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\input_manager.h"

void screen_dead_screen_load()
{
	engine_font_manager_draw_text( "DEAD SCREEN...!!", 2, 10 );
}

void screen_dead_screen_update( unsigned char *screen_type )
{
	unsigned char test;

	test = engine_input_manager_hold_right();
	if( test )
	{
		engine_font_manager_draw_text( "MUSIC", 4, 14 );
		engine_audio_manager_music_beat();
	}

	*screen_type = screen_type_dead;
}
