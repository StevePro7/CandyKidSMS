#include "test_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\command_manager.h"
#include "..\engine\delay_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\frame_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\tile_manager.h"

static unsigned char first_time;
static unsigned int undo_frame;

void screen_test_screen_load()
{
	engine_delay_manager_load( 0 );

	engine_font_manager_draw_text( "TESTER SCREEN!!", 4, 0 );
	engine_frame_manager_load();
	engine_frame_manager_draw();
	engine_delay_manager_draw();

	undo_frame = engine_command_manager_align_undo();
	engine_font_manager_draw_data( undo_frame, 31, 2 );
	first_time = 1;
}

void screen_test_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
	unsigned char proceed;
	unsigned int frame;
	frame = fo->frame_count;

	engine_frame_manager_draw();
	engine_delay_manager_draw();
	engine_font_manager_draw_data( undo_frame, 31, 2 );

	if( !first_time )
	{
		proceed = engine_delay_manager_update();
		if( !proceed )
		{
			*screen_type = screen_type_test;
			return;
		}

		engine_frame_manager_update();

		if( 0 == undo_frame )
		{
			*screen_type = screen_type_intro;
			return;
		}

		undo_frame--;
		first_time = 1;
	}

	engine_command_manager_undo( undo_frame );

	first_time = 0;
	*screen_type = screen_type_test;
}