#include "dead_screen.h"
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
#include "..\engine\move_manager.h"
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
static unsigned char prevs_direction;

void screen_dead_screen_load()
{
	engine_command_manager_init();
	engine_frame_manager_init();
	engine_delay_manager_load( 0 );

	engine_board_manager_init();
	engine_gamer_manager_init();
	engine_enemy_manager_init();
	engine_level_manager_init_board();
	engine_level_manager_init_exits();

	// Draw functions.
	engine_board_manager_debugger();
	engine_board_manager_side_tile();

	engine_level_manager_load_level( 0, 0 );
	engine_level_manager_draw_level();

	engine_frame_manager_draw();
	engine_delay_manager_draw();
	engine_font_manager_draw_text( "DEAD SCREEN!", 2, 10 );

	first_time = 1;
	frame_spot = 0;
	prevs_direction = direction_type_none;
}

void screen_dead_screen_update( unsigned char *screen_type )
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
			*screen_type = screen_type_dead;
			return;
		}

		engine_frame_manager_update();
		first_time = 1;
	}

	// Continue...
	frame = fo->frame_count;


	// Move gamer.
	if( direction_type_none != go->direction && lifecycle_type_move == go->lifecycle )
	{
		//  warning 110: conditional flow changed by optimizer: so said EVELYN the modified DOG
		engine_gamer_manager_update();
	}
	if( direction_type_none != go->direction && lifecycle_type_idle == go->lifecycle )
	{
		// Check collision.
		engine_font_manager_draw_data( frame, 12, 16 );
		engine_gamer_manager_stop();
	}
	// For continuity we want to check if actor can move immediately after stopping.
	if( direction_type_none == go->direction && lifecycle_type_idle == go->lifecycle )
	{
		if( 0 == frame )
		{
			engine_font_manager_draw_data( frame, 12, 14 );
			gamer_direction = direction_type_rght;
			engine_command_manager_add( frame, command_type_gamer_mover, gamer_direction );
		}
	}


	// Move enemies.
	enemy = actor_type_pro;
	//for( enemy = 0; enemy < MAX_ENEMIES; enemy++ )
	{
		eo = &global_enemy_objects[ enemy ];
		enemy_direction = direction_type_none;
		
		// Move enemy.
		if( direction_type_none != eo->direction && lifecycle_type_move == eo->lifecycle )
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
		// For continuity we want to check if actor can move immediately after stopping.
		if( direction_type_none == eo->direction && lifecycle_type_idle == eo->lifecycle )
		{
			//if( prevs_direction == direction_type_none )
			//{
			//	if( 0 == frame )
			//	{
			//		engine_font_manager_draw_data( frame, 12, 16 );
			//		enemy_direction = direction_type_rght;
			//		engine_command_manager_add( frame, command_type_enemy_mover, ( enemy | ( enemy_direction << 4 ) ) );
			//		prevs_direction = enemy_direction;
			//	}
			//}
			//else
			//{
			//	engine_font_manager_draw_data( frame, 12, 16 );
			//	enemy_direction = engine_move_manager_opposite_direction( prevs_direction );
			//	engine_command_manager_add( frame, command_type_enemy_mover, ( enemy | ( enemy_direction << 4 ) ) );
			//	prevs_direction = enemy_direction;
			//}
		}
	}


	// Execute all commands for this frame.
	engine_command_manager_execute( frame );


	first_time = 0;
	*screen_type = screen_type_dead;
}
