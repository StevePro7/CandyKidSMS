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

// PLAY screen - is the main command add + execute driver
static unsigned char first_time;
static unsigned char frame_spot;

void screen_play_screen_load()
{
	engine_command_manager_init();
	engine_frame_manager_init();
	engine_delay_manager_load( 20 );

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
	struct_enemy_object *eo;
	unsigned char gamer_direction = direction_type_none;
	unsigned char enemy_direction = direction_type_none;

	unsigned char proceed;
	//unsigned char input;
	unsigned char enemy;
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
		if( 0 == frame )
		{
			engine_font_manager_draw_data( frame, 12, 14 );
			engine_command_manager_add( frame, command_type_gamer_mover, direction_type_rght );
		}
		/*if( 40 == frame )
		{
			engine_command_manager_add( frame, command_type_end_gamer, 15 );
		}*/
		//input = engine_input_manager_hold_fire1();
		//if( input )
		//{
		//	engine_font_manager_draw_text( "END!", 17, 14 );
		//	engine_command_manager_add( frame, command_type_end_gamer, 15 );
		//	frame_spot = 1;
		//}
		//else
		//{
		//	gamer_direction = engine_gamer_manager_direction();
		//	if( direction_type_none != gamer_direction )
		//	{
		//		engine_font_manager_draw_data( gamer_direction, 10, 15 );
		//		//engine_font_manager_draw_data( frame_spot++, 27, 15 );
		//		engine_font_manager_draw_data( frame, 17, 17 );

		//		engine_command_manager_add( frame, command_type_kid_mover, gamer_direction );
		//	}
		//}
	}
	else if( direction_type_none != go->direction && lifecycle_type_move == go->lifecycle )
	{
		//  warning 110: conditional flow changed by optimizer: so said EVELYN the modified DOG
		engine_gamer_manager_update();
	}
	if( direction_type_none != go->direction && lifecycle_type_idle == go->lifecycle )
	{
		// Check collision.
		engine_font_manager_draw_data( frame, 12, 15 );
		engine_gamer_manager_stop();
	}


	// Move enemy.
	enemy = actor_type_pro;
	//for( enemy = 0; enemy < MAX_ENEMIES; enemy++ )
	{
		eo = &global_enemy_objects[ enemy ];
		enemy_direction = direction_type_none;
		if( direction_type_none == eo->direction && lifecycle_type_idle == eo->lifecycle )
		{
			if( 4 == frame )
			{
				engine_font_manager_draw_data( frame, 12, 16 );
				// TODO map enemy to command 
				//unsigned char command_type = engine_enemy_manager_get_mover( enemy );
				enemy_direction = direction_type_upxx;
				engine_command_manager_add( frame, command_type_enemy_mover, ( enemy | ( enemy_direction << 4 ) ) );
			}
		}
		else if( direction_type_none != eo->direction && lifecycle_type_move == eo->lifecycle )
		{
			//  warning 110: conditional flow changed by optimizer: so said EVELYN the modified DOG
			engine_enemy_manager_update( enemy );
		}
		if( direction_type_none != eo->direction && lifecycle_type_idle == eo->lifecycle )
		{
			// Check collision.
			engine_font_manager_draw_data( frame, 12, 17 );
			engine_enemy_manager_stop( enemy );

			engine_command_manager_add( frame, command_type_end_gamer, 0 );
			frame_spot = 1;
		}
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

		engine_font_manager_draw_text( "SAVING", 20, 12 );
		engine_command_manager_save();
		engine_storage_manager_write();
		engine_font_manager_draw_text( "SAVED!!!!", 20, 13 );

		*screen_type = screen_type_intro;
		//*screen_type = screen_type_demo;
		return;
	}

	*screen_type = screen_type_play;
}