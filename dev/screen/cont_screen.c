#include "cont_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\level_manager.h"

void screen_cont_screen_load()
{
	unsigned char tileX = 0;
	unsigned char tileY = 0;
	unsigned char tileZ = 0;

	engine_board_manager_init();
	engine_gamer_manager_init();
	engine_enemy_manager_init();

	engine_level_manager_init_board();
	engine_level_manager_init_exits();
	engine_level_manager_load_level(0, 0);

	tileZ = 59;
	engine_board_manager_calc_position( &tileX, &tileY, tileZ );

	engine_font_manager_draw_text( "CONT SCREEN!!", 2, 8 );

	//engine_font_manager_draw_data( board_homeZ[ 0 ], 10, 10 );
	//engine_font_manager_draw_data( board_homeZ[ 1 ], 10, 11 );
	//engine_font_manager_draw_data( board_homeZ[ 2 ], 10, 12 );
	//engine_font_manager_draw_data( board_homeZ[ 3 ], 10, 13 );
}

void screen_cont_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_cont;
}
