#include "beat_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\command_manager.h"
#include "..\engine\delay_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\frame_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\input_manager.h"

static unsigned char first_time;

void screen_beat_screen_load()
{
	unsigned char idx;
	unsigned char max = 32;
	unsigned int frame;
	unsigned char frames[ MAX_COMMANDS ];
	unsigned char commands[ MAX_COMMANDS ];
	unsigned int args[ MAX_COMMANDS ] =
	{
		direction_type_rght, direction_type_rght, direction_type_rght, direction_type_rght,
		direction_type_down, direction_type_down, direction_type_down, direction_type_down,
		direction_type_left, direction_type_left, direction_type_left, direction_type_left,
		direction_type_upxx, direction_type_upxx, direction_type_upxx, direction_type_upxx,
		direction_type_down, direction_type_down, direction_type_down, direction_type_down,
		direction_type_rght, direction_type_rght, direction_type_rght, direction_type_rght,
		direction_type_upxx, direction_type_upxx, direction_type_upxx, direction_type_upxx,
		direction_type_left, direction_type_left, direction_type_left, direction_type_left,
	};

	for( idx = 0; idx < max; idx++ )
	{
		frame = idx * 16;
		frames[ idx ] = frame % MAX_BYTE_SIZE;
		commands[ idx ] = engine_command_manager_type( frame, command_type_move );
	}

	engine_board_manager_init();
	engine_gamer_manager_init( KID_HOME_X, KID_HOME_Y );

	engine_command_manager_init();
	engine_command_manager_load( frames, commands, args );
	engine_delay_manager_load( 0 );
	engine_frame_manager_init();

	engine_font_manager_draw_text( "BEAT SCREEN!!", 4, 2 );
	engine_frame_manager_draw();
	engine_delay_manager_draw();
	first_time = 1;
}

void screen_beat_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
	struct_gamer_object *go = &global_gamer_object;
	unsigned char proceed;
	//unsigned char input;
	unsigned int frame = fo->frame_count;

	// Draw sprites first.
	engine_gamer_manager_draw();

	//engine_frame_manager_draw();
	//engine_delay_manager_draw();
	if( !first_time )
	{
		proceed = engine_delay_manager_update();
		if( !proceed )
		{
			*screen_type = screen_type_beat;
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

	first_time = 0;
	*screen_type = screen_type_beat;
}