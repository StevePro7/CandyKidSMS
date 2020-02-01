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

	// WIP - I might just leave this out!!
	// and use 31 end game to signal check
	// IMPORTANT must have this or else not work
	// Signal the start of the command collection:
	//engine_command_manager_add( 0, command_type_all_empty, 0 );		

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
	/*if( frame < 254 )
	{
		engine_command_manager_add( frame, my_command, 256 + frame );
		my_command++;
		if( my_command > 8 )
		{
			my_command = 1;
		}
	}*/
	input[ 0 ] = 5 == frame;
	if( input[ 0 ] )
	{
	//	//engine_command_manager_add( frame, command_type_all_empty, 5 );
		engine_command_manager_add( frame, command_type_pro_mover, 05 );
		engine_command_manager_add( frame, command_type_kid_mover, 10 );
	}
	//input[ 1 ] = 290 == frame;
	//if( input[1] )
	//{
	//	engine_command_manager_add( frame, command_type_kid_mover, 10 );
	//	//engine_command_manager_add( frame, command_type_pro_mover, 1010 );
	//}
	//input[ 2 ] = 604 == frame;
	//if( input[2] )
	//{
	//	engine_command_manager_add( frame, command_type_pro_mover, 20 );
	//}
	//input[ 3 ] = 768 == frame;
	//if( input[ 3 ] )
	//{
	//	engine_command_manager_add( frame, command_type_adi_mover, 30 );
	//}
	//input[ 4 ] = 1049 == frame;
	//if( input[ 4 ] )
	//{
	//	engine_command_manager_add( frame, command_type_suz_mover, 40 );
	//}
	//input[ 5 ] = 1400 == frame;
	//if( input[ 5 ] )
	//{
	//	engine_command_manager_add( frame, command_type_kid_speed, 50 );
	//}
	//input[ 6 ] = 1729 == frame;
	//if( input[ 6 ] )
	//{
	//	engine_command_manager_add( frame, command_type_pro_speed, 60 );
	//}
	//input[ 7 ] = 2001 == frame;
	//if( input[ 7 ] )
	//{
	//	engine_command_manager_add( frame, command_type_adi_speed, 70 );
	//}

	input[ 8 ] = 7 == frame;
	if( input[ 8 ] )
	{
		engine_command_manager_add( frame, command_type_end_gamer, 15 );
	}


	// Execute all commands for this frame.
	engine_command_manager_execute( frame );


	if( input[8] )
	{
		engine_frame_manager_draw();

		engine_font_manager_draw_text( "SAVING", 20, 17 );
		engine_command_manager_save();
		engine_storage_manager_write();
		engine_font_manager_draw_text( "SAVED!!!!", 20, 18 );

		*screen_type = screen_type_test;
		//*screen_type = screen_type_intro;
		return;
	}

	first_time = 0;
	*screen_type = screen_type_record;
}