#include "cont_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\gamer_manager.h"

void screen_cont_screen_load()
{
	unsigned char tileX = 0;
	unsigned char tileY = 0;
	unsigned char tileZ = 0;
	engine_board_manager_init();
	engine_gamer_manager_init();
	engine_enemy_manager_init();

	tileZ = 59;
	engine_board_manager_calc_position( &tileX, &tileY, tileZ );

	engine_font_manager_draw_text( "CONT SCREEN..!!", 2, 8 );
}

void screen_cont_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_cont;
}
