#include "board_manager.h"
#include "enum_manager.h"
#include "global_manager.h"
#include "tile_manager.h"

// Global variable.
struct_board_object global_board_object;

// Methods.
void engine_board_manager_init()
{
	struct_board_object *bo = &global_board_object;
	unsigned char loop;
	unsigned char data;
	unsigned char left = SCREEN_TILE_LEFT * TILE_HALF;

	bo->save_tree_type = tree_type_avoid;
	//bo->save_exit_type = exit_type_closed;
	bo->save_exit_type = exit_type_public;

	for( loop = 0; loop < TREE_ROWS; loop++ )
	{
		data = loop * TILE_SIZE;
		bo->posnX[ loop ] = data + left;
		bo->posnY[ loop ] = data;
	}
}

void engine_board_manager_set_exit_type( unsigned char exit_type )
{
	struct_board_object *bo = &global_board_object;
	bo->save_exit_type = exit_type;
}

void engine_board_manager_set_tree_type( unsigned char tree_type )
{
	struct_board_object *bo = &global_board_object;
	bo->save_tree_type = tree_type;
}

void engine_board_manager_draw_edge()
{
	// top
	engine_tile_manager_draw_blank( SCREEN_TILE_LEFT + 6, 0 );
	engine_tile_manager_draw_blank( SCREEN_TILE_LEFT + 16, 0 );

	// bot
	engine_tile_manager_draw_blank( SCREEN_TILE_LEFT + 6, 22 );
	engine_tile_manager_draw_blank( SCREEN_TILE_LEFT + 16, 22 );

	// lft
	engine_tile_manager_draw_blank( SCREEN_TILE_LEFT, 6 );
	engine_tile_manager_draw_blank( SCREEN_TILE_LEFT, 16 );

	// rgt
	engine_tile_manager_draw_blank( SCREEN_TILE_LEFT + 22, 6 );
	engine_tile_manager_draw_blank( SCREEN_TILE_LEFT + 22, 16 );
}