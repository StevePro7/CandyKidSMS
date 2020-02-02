#include "intro_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\command_manager.h"
#include "..\engine\content_manager.h"
#include "..\engine\delay_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\frame_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\sprite_manager.h"
#include "..\engine\tile_manager.h"

static unsigned char first_time;
static unsigned int undo_frame;

void screen_intro_screen_load()
{
	// draw Candy Kid title
	//engine_content_manager_load_title();
	//engine_tile_manager_main_title( 2, 2 );

	//engine_board_manager_debugger();

	/*unsigned int frames[ MAX_COMMANDS ] = { 768, 1049, 1400, 1729, 2001, 3000 };
	unsigned char commands[ MAX_COMMANDS ];
	unsigned char args[ MAX_COMMANDS ];

	unsigned char loop;
	for( loop = 6; loop < 253; loop++ )
	{
		frames[ loop ] = loop;
		commands[ loop ] = 9;
		args[ loop ] = loop;
	}*/

	/*frames[ 0 ] = 768; frames[ 1 ] = 1049; frames[ 2 ] = 1400; frames[ 3 ] = 1729; frames[ 4 ] = 2001; frames[ 5 ] = 3000;
	frames[ 253 ] = 254; frames[ 254 ] = 300; 	frames[ 255 ] = 604;

	commands[ 0 ] = 3; 	commands[ 1 ] = 4; 	commands[ 2 ] = 5; 	commands[ 3 ] = 6; 	commands[ 4 ] = 7; 	commands[ 5 ] = 31;
	commands[ 253 ] = 2;  commands[ 254 ] = 1;  commands[ 255 ] = 2;

	args[ 0 ] = 30; args[ 1 ] = 40; args[ 2 ] = 50; args[ 3 ] = 60; args[ 4 ] = 70; args[ 5 ] = 4;
	args[ 253 ] = 5; args[ 254 ] = 10; args[ 255 ] = 20;

	engine_command_manager_load( frames, commands, args );


	engine_delay_manager_load( 10 );

	
	engine_frame_manager_load();
	engine_frame_manager_draw();
	engine_delay_manager_draw();

	undo_frame = engine_command_manager_align_undo();
	engine_font_manager_draw_data( undo_frame, 31, 2 );*/

	engine_board_manager_init();
	engine_gamer_manager_init();
	engine_enemy_manager_init();

	engine_font_manager_draw_text( "INTR SCREEN...!!", 2, 10 );
	first_time = 1;
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	unsigned char input;

	// Draw sprites first.
	engine_gamer_manager_draw();
	engine_enemy_manager_draw();

	input = engine_input_manager_hold_fire2();
	if( input )
	{
		//*screen_type = screen_type_demo;
		return;
	}

	*screen_type = screen_type_intro;
}
