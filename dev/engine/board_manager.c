#include "board_manager.h"
#include "enum_manager.h"
#include "global_manager.h"
#include "tile_manager.h"

// Global variable.
struct_board_object global_board_object;

static void draw_side( unsigned char wide, unsigned char right );

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

	// TODO delete as will be set before hand!!
	bo->save_tree_type = tree_type_death;

	bo->top = 0;
	bo->bottom = ( SCREEN_TILE_HIGH - 1 ) * 2;
	bo->left = SCREEN_TILE_LEFT;
	bo->right = SCREEN_TILE_LEFT + ( SCREEN_TILE_WIDE - 2 ) * 2;
	bo->right2 = SCREEN_TILE_LEFT + ( TREE_COLS - 1 ) * 2;
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

void engine_board_manager_main_full()
{
	struct_board_object *bo = &global_board_object;
	draw_side( SCREEN_TILE_WIDE - 1, bo->right );
	//draw_side( TREE_COLS, bo->right2 );

	/*unsigned char type = bo->save_tree_type;
	unsigned char loop;

	for( loop = 0; loop < SCREEN_TILE_WIDE - 1; loop ++ )
	{
		engine_tile_manager_main_trees( type, bo->left + loop * 2, bo->top );
		engine_tile_manager_main_trees( type, bo->left + loop * 2, bo->bottom );
	}
	for( loop = 1; loop < SCREEN_TILE_HIGH - 1; loop++ )
	{
		engine_tile_manager_main_trees( type, bo->left, bo->top + loop * 2 );
		engine_tile_manager_main_trees( type, bo->right, bo->top + loop * 2 );
	}*/
}
void engine_board_manager_main_edge()
{
	struct_board_object *bo = &global_board_object;
	// top
	engine_tile_manager_draw_blank( SCREEN_TILE_LEFT + 8, 0 );
	engine_tile_manager_draw_blank( SCREEN_TILE_LEFT + 20, 0 );

	// bot
	engine_tile_manager_draw_blank( SCREEN_TILE_LEFT + 8, 22 );
	engine_tile_manager_draw_blank( SCREEN_TILE_LEFT + 20, 22 );

	// lft
	engine_tile_manager_draw_blank( SCREEN_TILE_LEFT, 6 );
	engine_tile_manager_draw_blank( SCREEN_TILE_LEFT, 16 );

	// rgt
	engine_tile_manager_draw_blank( SCREEN_TILE_LEFT + 22, 6 );
	engine_tile_manager_draw_blank( SCREEN_TILE_LEFT + 22, 16 );
}

static void draw_side( unsigned char wide, unsigned char right )
{
	struct_board_object *bo = &global_board_object;
	unsigned char type = bo->save_tree_type;
	unsigned char loop;

	for( loop = 0; loop < wide; loop++ )
	{
		engine_tile_manager_main_trees( type, bo->left + loop * 2, bo->top );
		engine_tile_manager_main_trees( type, bo->left + loop * 2, bo->bottom );
	}
	for( loop = 1; loop < SCREEN_TILE_HIGH - 1; loop++ )
	{
		engine_tile_manager_main_trees( type, bo->left, bo->top + loop * 2 );
		engine_tile_manager_main_trees( type, right, bo->top + loop * 2 );
	}
}