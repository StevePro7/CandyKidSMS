#include "func_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\command_manager.h"
#include "..\engine\delay_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\frame_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\storage_manager.h"
#include "..\engine\tile_manager.h"

static unsigned char first_time;

void screen_func_screen_load()
{
	unsigned char test;

	engine_board_manager_init();
	engine_gamer_manager_init( KID_HOME_X, KID_HOME_Y );

	engine_command_manager_init();
	engine_delay_manager_load( 10 );
	engine_frame_manager_init();

	engine_font_manager_draw_text( "FUNCTN SCREEN!!", 4, 0 );
	engine_frame_manager_draw();
	engine_delay_manager_draw();
	first_time = 1;

	test = engine_storage_manager_available();
	if( test )
	{
		engine_storage_manager_read();
	}

	engine_tile_manager_draw_tree( tree_type_death, 4, 2 );	engine_tile_manager_draw_tree( tree_type_death, 6, 2 );	engine_tile_manager_draw_tree( tree_type_death, 8, 2 );
	engine_tile_manager_draw_tree( tree_type_death, 10, 4 );	engine_tile_manager_draw_tree( tree_type_death, 10, 6 );	engine_tile_manager_draw_tree( tree_type_death, 8, 8 );
	engine_tile_manager_draw_tree( tree_type_death, 6, 8 );

	engine_font_manager_draw_data( test, 22, 7 );
}

void screen_func_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
	struct_gamer_object *go = &global_gamer_object;
	unsigned char proceed;
	unsigned char input;
	unsigned int frame = fo->frame_count;

	// Draw sprites first.
	engine_gamer_manager_draw();

	engine_frame_manager_draw();
	engine_delay_manager_draw();
	if( !first_time )
	{
		proceed = engine_delay_manager_update();
		if( !proceed )
		{
			*screen_type = screen_type_func;
			return;
		}

		engine_frame_manager_update();
		first_time = 1;
	}

	// Continue...
	frame = fo->frame_count;

	// Move gamer.
	if( direction_type_none == go->direction && lifecycle_type_idle == go->lifecycle )
	{
		
	}
	else if( direction_type_none != go->direction && lifecycle_type_move == go->lifecycle )
	{
		//  warning 110: conditional flow changed by optimizer: so said EVELYN the modified DOG
		engine_gamer_manager_update();
	}
	if( direction_type_none != go->direction && lifecycle_type_idle == go->lifecycle )
	{
		// Check collision.
		engine_gamer_manager_stop();
	}

	// Execute all commands for this frame.
	engine_command_manager_execute( frame );

	// Finish
	input = 100 == frame;
	if( input )
	{
		engine_frame_manager_draw();

		engine_font_manager_draw_text( "ENDING", 20, 18 );
		engine_font_manager_draw_text( "ENDED!!!!", 20, 19 );

		*screen_type = screen_type_intro;
		return;
	}

	first_time = 0;
	*screen_type = screen_type_func;
}