#include "cont_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\command_manager.h"
#include "..\engine\delay_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\frame_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\level_manager.h"
#include "..\engine\move_manager.h"

void screen_cont_screen_load()
{
	engine_command_manager_init();
	engine_frame_manager_init();
	engine_delay_manager_load( 0 );

	engine_board_manager_init();
	engine_gamer_manager_init();
	engine_enemy_manager_init();
	engine_level_manager_init_board();
	engine_level_manager_init_exits();

	// Draw functions.
	engine_board_manager_debugger();
	engine_board_manager_side_tile();

	engine_level_manager_load_level( 0, 0 );
	engine_level_manager_draw_level();

	//engine_frame_manager_draw();
	//engine_delay_manager_draw();
	engine_font_manager_draw_text( "CONT SCREEN!!", 2, 7 );
}

void screen_cont_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
	struct_gamer_object *go = &global_gamer_object;
	unsigned char tile_type;
	unsigned char coll_type;

	// Draw sprites first.
	engine_gamer_manager_draw();
	//engine_enemy_manager_draw();

	// TODO delete
	tile_type = engine_level_manager_get_tile_type( go->tileX, go->tileY );
	coll_type = engine_level_manager_get_collision( go->tileX, go->tileY, direction_type_upxx );
	// TODO delete

	*screen_type = screen_type_cont;
}
