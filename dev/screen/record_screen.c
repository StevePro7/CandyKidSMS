#include "record_screen.h"
#include "..\engine\command_manager.h"
#include "..\engine\delay_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\frame_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\storage_manager.h"

static unsigned char first_time;
static unsigned char my_command;

void screen_record_screen_load()
{
	unsigned char test;

	engine_command_manager_init();
	engine_frame_manager_init();
	engine_delay_manager_load( 0 );

	engine_font_manager_draw_text( "RECORD SCREEN!!", 4, 0 );
	engine_frame_manager_draw();
	engine_delay_manager_draw();
	first_time = 1;

	test = engine_storage_manager_available();
	if( test )
	{
		engine_storage_manager_read();
	}

	engine_font_manager_draw_data( test, 22, 7 );
	my_command = 1;
}

void screen_record_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
	unsigned char proceed;
	unsigned char input[9];
	unsigned int frame;
	frame = fo->frame_count;

	engine_frame_manager_draw();
	engine_delay_manager_draw();
	if( !first_time )
	{
		proceed = engine_delay_manager_update();
		if( !proceed )
		{
			*screen_type = screen_type_record;
			return;
		}

		engine_frame_manager_update();
		first_time = 1;
	}

	frame = fo->frame_count;
	if( frame < 248 )
	{
		engine_command_manager_add( frame, my_command, 256 + frame );
		my_command++;
		if( my_command > 8 )
		{
			my_command = 1;
		}
	}
	//input[ 0 ] = 16 == frame;
	//if( input[ 0 ] )
	//{
	//	//engine_command_manager_add( frame, command_type_empty, 5 );
	//	engine_command_manager_add( frame, command_type_jump, 05 );
	//}
	input[ 1 ] = 300 == frame;
	if( input[1] )
	{
		engine_command_manager_add( frame, command_type_fire, 10 );
		//engine_command_manager_add( frame, command_type_jump, 1010 );
	}
	input[ 2 ] = 604 == frame;
	if( input[2] )
	{
		engine_command_manager_add( frame, command_type_jump, 20 );
	}
	input[ 3 ] = 768 == frame;
	if( input[ 3 ] )
	{
		engine_command_manager_add( frame, command_type_move, 30 );
	}
	input[ 4 ] = 1049 == frame;
	if( input[ 4 ] )
	{
		engine_command_manager_add( frame, command_type_bank4, 40 );
	}
	input[ 5 ] = 1400 == frame;
	if( input[ 5 ] )
	{
		engine_command_manager_add( frame, command_type_bank5, 50 );
	}
	input[ 6 ] = 1729 == frame;
	if( input[ 6 ] )
	{
		engine_command_manager_add( frame, command_type_bank6, 60 );
	}
	input[ 7 ] = 2001 == frame;
	if( input[ 7 ] )
	{
		engine_command_manager_add( frame, command_type_bank7, 70 );
	}

	input[ 8 ] = 2047 == frame;
	if( input[ 8 ] )
	{
		engine_command_manager_add( frame, command_type_session, 4 );
	}


	// Execute all commands for this frame.
	engine_command_manager_execute( frame );


	if( input[8] )
	{
		engine_frame_manager_draw();

		engine_font_manager_draw_text( "SAVING", 20, 18 );
		engine_command_manager_save();
		engine_storage_manager_write();
		engine_font_manager_draw_text( "SAVED!!!!", 20, 19 );

		*screen_type = screen_type_test;
		//*screen_type = screen_type_intro;
		return;
	}

	first_time = 0;
	*screen_type = screen_type_record;
}