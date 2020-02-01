#include "board_manager.h"
#include "enum_manager.h"
#include "global_manager.h"
#include "tile_manager.h"

#define TOP_EXIT_Y		6
#define BOT_EXIT_Y		16
// Global variable.
struct_board_object global_board_object;

static void draw_side( unsigned char wide, unsigned char right );
static void draw_gaps( unsigned char left, unsigned char midd, unsigned char right );

// Methods.
void engine_board_manager_init()
{
	struct_board_object *bo = &global_board_object;
	unsigned char loop;
	unsigned char left = SCREEN_TILE_LEFT * TILE_HALF;
	int data;
	signed char offset;

	for( loop = 0; loop < MAZE_ROWS; loop++ )
	{
		offset = loop - 1;
		data = offset * TILE_SIZE;
		bo->posnX[ loop ] = data + left;
		bo->posnY[ loop ] = data;
	}

	// TODO delete as will be set before hand!!
	bo->save_tree_type = tree_type_avoid;
	bo->save_exit_type = exit_type_public;
	// TODO delete as will be set before hand!!

	bo->top		= 0;
	bo->bottom	= ( SCREEN_TILE_HIGH - 1 ) * 2;
	bo->left	= SCREEN_TILE_LEFT;
	bo->right	= SCREEN_TILE_LEFT + ( SCREEN_TILE_WIDE - 2 ) * 2;
	bo->right2	= SCREEN_TILE_LEFT + ( TREE_COLS - 1 ) * 2;
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

void engine_board_manager_draw_full()
{
	struct_board_object *bo = &global_board_object;
	draw_side( TREE_COLS, bo->right2 );
}
void engine_board_manager_draw_exit()
{
	struct_board_object *bo = &global_board_object;
	draw_gaps( TOP_EXIT_Y, BOT_EXIT_Y, bo->right2 );
}

void engine_board_manager_main_full()
{
	struct_board_object *bo = &global_board_object;
	draw_side( SCREEN_TILE_WIDE - 1, bo->right );
}
void engine_board_manager_main_exit()
{
	struct_board_object *bo = &global_board_object;
	draw_gaps( 8, 20, bo->right );
}

// This is the function that draws opaque tile to hide Kid when moving thru exit!
void engine_board_manager_side_tile()
{
	engine_tile_manager_draw_sides( SCREEN_TILE_LEFT - 2, TOP_EXIT_Y );
	engine_tile_manager_draw_sides( SCREEN_TILE_LEFT - 2, BOT_EXIT_Y );

	engine_tile_manager_draw_sides( TREE_COLS * 2 + SCREEN_TILE_LEFT, BOT_EXIT_Y );
	engine_tile_manager_draw_sides( TREE_COLS * 2 + SCREEN_TILE_LEFT, TOP_EXIT_Y );
}

// TODO - delete!!
void engine_board_manager_debugger()
{
	struct_board_object *bo = &global_board_object;
	unsigned char type = bo->save_tree_type;

	unsigned char spot[] = { 1, 2, 4, 7, 9, 10 };
	unsigned char loop;
	//for( loop = 0; loop < 6; loop++ )
	for( loop = 0; loop < 2; loop++ )
	{
		engine_tile_manager_main_trees( type, SCREEN_TILE_LEFT + spot[ loop ] * 2, 0 );
		engine_tile_manager_main_trees( type, SCREEN_TILE_LEFT + spot[ loop ] * 2, 22 );

		engine_tile_manager_main_trees( type, SCREEN_TILE_LEFT, spot[ loop ] * 2 );
		engine_tile_manager_main_trees( type, SCREEN_TILE_LEFT + 22, spot[ loop ] * 2 );
	}
}
// TODO - delete!!

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
static void draw_gaps( unsigned char left, unsigned char midd, unsigned char right )
{
	struct_board_object *bo = &global_board_object;
	unsigned char type = bo->save_tree_type;
	if( exit_type_closed == bo->save_exit_type )
	{
		engine_tile_manager_main_trees(  type,SCREEN_TILE_LEFT + left, bo->top );
		engine_tile_manager_main_trees(  type,SCREEN_TILE_LEFT + midd, bo->top );
		engine_tile_manager_main_trees(  type,SCREEN_TILE_LEFT + left, bo->bottom );
		engine_tile_manager_main_trees(  type,SCREEN_TILE_LEFT + midd, bo->bottom );

		// Hard code top and bottom exits as they never move!
		engine_tile_manager_main_trees(  type,bo->left, 6 );
		engine_tile_manager_main_trees(  type,bo->left, 16 );
		engine_tile_manager_main_trees(  type,right, 6 );
		engine_tile_manager_main_trees(  type,right, 16 );

		return;
	}

	// Otherwise "draw" exits as blank tiles.
	engine_tile_manager_draw_blank( SCREEN_TILE_LEFT + left, bo->top );
	engine_tile_manager_draw_blank( SCREEN_TILE_LEFT + midd, bo->top );
	engine_tile_manager_draw_blank( SCREEN_TILE_LEFT + left, bo->bottom );
	engine_tile_manager_draw_blank( SCREEN_TILE_LEFT + midd, bo->bottom );

	// Hard code top and bottom exits as they never move!
	engine_tile_manager_draw_blank( bo->left, TOP_EXIT_Y );
	engine_tile_manager_draw_blank( bo->left, BOT_EXIT_Y );
	engine_tile_manager_draw_blank( right, TOP_EXIT_Y );
	engine_tile_manager_draw_blank( right, BOT_EXIT_Y );
}