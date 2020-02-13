#include "test_screen.h"
#include "..\engine\audio_manager.h"
#include "..\engine\board_manager.h"
#include "..\engine\command_manager.h"
#include "..\engine\delay_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\frame_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\move_manager.h"
#include "..\engine\tile_manager.h"

#define BYTE_NIBBLE_MASK	0x0F

static unsigned char first_time;
static unsigned int undo_frame;

// TODO move to function_manager
static void split( unsigned char byte, unsigned char *upper_nibble, unsigned char *lower_nibble );

void screen_test_screen_load()
{
	unsigned char byte = 0;
	unsigned char upper_nibble = 0;
	unsigned char lower_nibble = 0;
	engine_font_manager_draw_text( "TEST SCREEN...!!", 4, 0 );

	engine_board_manager_init();
	/*

	// xDist = 0;	Sort = 3; Half = 1;		Byte = 49.
	byte = engine_move_manager_find_direction( 18, 14, 18, 23 );
	split( byte, &upper_nibble, &lower_nibble );

	// yDist = 0;	Sort = 0; Half = 1;		Byte = 1.
	byte = engine_move_manager_find_direction( 15, 23, 18, 23 );
	split( byte, &upper_nibble, &lower_nibble );


	// Index = 0;	Sort = 0; Half = 0;		Byte = 0.
	byte = engine_move_manager_find_direction( 18, 11, 27, 7 );
	split( byte, &upper_nibble, &lower_nibble );

	// Index = 1;	Sort = 0; Half = 1;		Byte = 1.
	byte = engine_move_manager_find_direction( 21, 1, 26, 1 );
	split( byte, &upper_nibble, &lower_nibble );


	// Index = 2;	Sort = 1; Half = 0;		Byte = 16.
	byte = engine_move_manager_find_direction( 18, 11, 6, 5 );
	split( byte, &upper_nibble, &lower_nibble );

	// Index = 3;	Sort = 1; Half = 1;		Byte = 17.
	byte = engine_move_manager_find_direction( 26, 5, 21, 5 );
	split( byte, &upper_nibble, &lower_nibble );


	// Index = 4;	Sort = 2; Half = 0;		Byte = 32.
	byte = engine_move_manager_find_direction( 18, 14, 21, 5 );
	split( byte, &upper_nibble, &lower_nibble );

	// Index = 5;	Sort = 2; Half = 1;		Byte = 33.
	byte = engine_move_manager_find_direction( 9, 11, 13, 23 );
	split( byte, &upper_nibble, &lower_nibble );


	// Index = 6;	Sort = 3; Half = 0;		Byte = 48.
	byte = engine_move_manager_find_direction( 21, 14, 21, 5 );
	split( byte, &upper_nibble, &lower_nibble );

	// Index = 7;	Sort = 3; Half = 1;		Byte = 49.
	byte = engine_move_manager_find_direction( 18, 11, 13, 23 );
	split( byte, &upper_nibble, &lower_nibble );

	*/
	engine_audio_manager_music_game( 0 );
	//engine_audio_manager_music_beat();
}

void screen_test_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_test;
}

static void split( unsigned char byte, unsigned char *upper_nibble, unsigned char *lower_nibble )
{
	*upper_nibble = ( byte >> 4 ) & BYTE_NIBBLE_MASK;
	*lower_nibble = byte & BYTE_NIBBLE_MASK;
}