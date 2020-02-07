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
	engine_font_manager_draw_text( "CONT SCREEN....!!", 2, 7 );
//	engine_move_manager_init();
}

void screen_cont_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
	struct_gamer_object *go = &global_gamer_object;
	struct_enemy_object *eo;

	unsigned char direction;
	unsigned char tile_type;
	unsigned char next_tile;
	unsigned char twos_tile;
	unsigned char coll_type;
	unsigned char gx, gy;
	coll_type = move_find_direction[ 10 ];
 
	eo = &global_enemy_objects[ actor_type_pro ];

	// Draw sprites first.
	engine_gamer_manager_draw();
	//engine_enemy_manager_draw();

	direction = direction_type_rght;

	// TODO delete
	//tile_type = engine_level_manager_get_tile_type( go->tileX, go->tileY );
	next_tile = engine_level_manager_get_next_tile( go->tileX, go->tileY, direction, offset_type_one );
	//engine_board_manager_calc_position( &gx, &gy, next_tile );
	twos_tile = engine_level_manager_get_next_tile( go->tileX, go->tileY, direction, offset_type_two );
	engine_board_manager_calc_position( &gx, &gy, twos_tile );


	//direction = engine_move_manager_exec_direction();
	direction = engine_move_manager_find_direction( eo->tileX, eo->tileY, gx, gy );


	coll_type = engine_level_manager_get_next_coll( go->tileX, go->tileY, direction);

	direction = engine_gamer_manager_mover_direction();
	tile_type = engine_gamer_manager_mover_direction();
	engine_font_manager_draw_data( direction, 17, 7 );
	// TODO delete

	*screen_type = screen_type_cont;
}
