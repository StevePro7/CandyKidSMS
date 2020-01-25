#include "intro_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\event_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\global_manager.h"
#include "..\engine\mask_manager.h"
#include "..\engine\move_manager.h"
#include "..\engine\sprite_manager.h"

void screen_intro_screen_load()
{
	// Store frames no. max 2048 i.e. range [0-2047]
	// Store 256 frame in byte with 8x possible banks	8x256 = 2048
	// As there are max 32x commands so only consume bottom 5bits
	// Therefore store the frame bank in the top 3bits of command
	//unsigned char new_frame = 3;
	////unsigned char new_command = 5;				// bank = 0	command = 5
	//unsigned char new_command = 0x05;			// bank = 1	command = 5
	//unsigned char tst_command;

	//unsigned int frame = 259;
	//unsigned int chk_frame;
	//unsigned char div = frame / MAX_BYTE_SIZE;
	//unsigned char mod = frame % MAX_BYTE_SIZE;

	//unsigned char bank = div << 5;
	//tst_command = new_command - bank;
	//chk_frame = div * MAX_BYTE_SIZE + 3;
	//unsigned char byt = 0xFE;
	//unsigned char cmd = 7;
	//unsigned char bin = cmd | FRAME_BANK_7;
	//unsigned char sht = bin >> 5;				// TOO magic number to define

	engine_font_manager_draw_text( "INTRO  SCREEN!!", 4, 0 );
	/*engine_font_manager_draw_data( frame, 10, 1 );
	engine_font_manager_draw_data( div, 10, 2 );
	engine_font_manager_draw_data( mod, 10, 3 );
	engine_font_manager_draw_data( byt, 10, 4 );
	engine_font_manager_draw_data( bin, 10, 5 );*/
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_intro;
}