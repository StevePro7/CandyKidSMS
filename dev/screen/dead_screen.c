#include "dead_screen.h"
#include "..\devkit\_snd_manager.h"
#include "..\engine\audio_manager.h"
#include "..\engine\delay_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\frame_manager.h"
#include "..\engine\input_manager.h"

static unsigned char first_time;

void screen_dead_screen_load()
{
	engine_frame_manager_init();
	engine_delay_manager_load( 0 );

	engine_font_manager_draw_text( "DEAD SCREEN..!!", 2, 10 );
	//devkit_PSGSetMusicVolumeAttenuation( 0 );		// sound on
	//devkit_PSGSetMusicVolumeAttenuation( 15 );		// sound off
	//engine_audio_manager_music_game( 0 );

	first_time = 1;
}

void screen_dead_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
	unsigned char proceed;
	unsigned char input;
	unsigned int frame;
	frame = fo->frame_count;

	engine_frame_manager_draw();
	engine_delay_manager_draw();
	if( !first_time )
	{
		proceed = engine_delay_manager_update();
		if( !proceed )
		{
			*screen_type = screen_type_dead;
			return;
		}

		engine_frame_manager_update();
		first_time = 1;
	}

	// Continue...
	frame = fo->frame_count;

	input = engine_input_manager_hold_right();
	if( input )
	{
	}

	first_time = 0;
	*screen_type = screen_type_dead;
}
