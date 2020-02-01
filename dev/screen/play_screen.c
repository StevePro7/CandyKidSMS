#include "play_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\command_manager.h"
#include "..\engine\delay_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\frame_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\level_manager.h"
#include "..\engine\storage_manager.h"
#include "..\engine\sprite_manager.h"
#include "..\engine\tile_manager.h"

// IMPORTANT disable compiler warning 110
#ifdef _CONSOLE
#else
#pragma disable_warning 110
#endif

static unsigned char first_time;
static unsigned char frame_spot;

void screen_play_screen_load()
{
	engine_command_manager_init();
	engine_frame_manager_init();
	engine_delay_manager_load( 0 );

	engine_board_manager_init();
	engine_gamer_manager_init();
	engine_enemy_manager_init();

	engine_frame_manager_draw();
	engine_delay_manager_draw();

	engine_board_manager_debugger();
	engine_board_manager_debugger();
	engine_board_manager_side_tile();

	engine_level_manager_init_board();
	engine_level_manager_init_exits();

	engine_level_manager_load_level( 0, 0 );
	engine_level_manager_draw_level();

	engine_font_manager_draw_text( "PLAY SCREEN!", 2, 10 );

	first_time = 1;
	frame_spot = 0;
}

void screen_play_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
	struct_gamer_object *go = &global_gamer_object;
	unsigned char gamer_direction = direction_type_none;

	unsigned char proceed;
	unsigned char input;
	unsigned int frame;
	frame = fo->frame_count;

	// Draw sprites first.
	engine_gamer_manager_draw();
	engine_enemy_manager_draw();

	engine_frame_manager_draw();
	engine_delay_manager_draw();
	if( !first_time )
	{
		proceed = engine_delay_manager_update();
		if( !proceed )
		{
			*screen_type = screen_type_play;
			return;
		}

		engine_frame_manager_update();
		first_time = 1;
	}

	// Continue...
	frame = fo->frame_count;
	frame_spot = 0;

	// Move gamer.
	if( direction_type_none == go->direction && lifecycle_type_idle == go->lifecycle )
	{
		/*if( 0 == frame || 20 == frame )
		{
			engine_font_manager_draw_data( frame, 17, 17 );
			engine_command_manager_add( frame, command_type_kid_mover, direction_type_rght );
		}
		if( 40 == frame )
		{
			engine_command_manager_add( frame, command_type_end_gamer, 15 );
		}*/
		input = engine_input_manager_hold_fire1();
		if( input )
		{
			engine_font_manager_draw_text( "END!", 17, 14 );
			engine_command_manager_add( frame, command_type_end_gamer, 15 );
			frame_spot = 1;
		}
		else
		{
			gamer_direction = engine_gamer_manager_direction();
			if( direction_type_none != gamer_direction )
			{
				engine_font_manager_draw_data( gamer_direction, 10, 15 );
				//engine_font_manager_draw_data( frame_spot++, 27, 15 );
				engine_font_manager_draw_data( frame, 17, 17 );

				engine_command_manager_add( frame, command_type_kid_mover, gamer_direction );
			}
		}
	}
	else if( direction_type_none != go->direction && lifecycle_type_move == go->lifecycle )
	{
		//  warning 110: conditional flow changed by optimizer: so said EVELYN the modified DOG
		engine_gamer_manager_update();
	}
	if( direction_type_none != go->direction && lifecycle_type_idle == go->lifecycle )
	{
		// Check collision.
		engine_font_manager_draw_data( frame, 17, 18 );
		engine_gamer_manager_stop();
	}

	// Execute all commands for this frame.
	engine_command_manager_execute( frame );


	/*gamer_direction = engine_gamer_manager_direction();
	if( direction_type_none != gamer_direction )
	{
		engine_font_manager_draw_text( "RIGHT", 10, 15 );
		go->posnX++;
	}*/

	first_time = 0;
	if( frame_spot )
	{
		engine_frame_manager_draw();
		engine_delay_manager_draw();

		engine_font_manager_draw_text( "SAVING", 20, 17 );
		engine_command_manager_save();
		engine_storage_manager_write();
		engine_font_manager_draw_text( "SAVED!!!!", 20, 18 );

		*screen_type = screen_type_intro;
		//*screen_type = screen_type_demo;
		return;
	}

	*screen_type = screen_type_play;
}