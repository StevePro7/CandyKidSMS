#include "level_manager.h"

#include "global_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "tile_manager.h"
#include "..\devkit\_sms_manager.h"
#include <stdlib.h>

// Global variable.
struct_level_object global_level_object;

#define CRLF	2				// char
#define CR		'\r'			// 0x0d
#define LF		'\n'			// 0x0a

// Private helper methods.
static void load_level( const unsigned char *data, const unsigned char bank, const unsigned char size );
static void draw_tiles( unsigned char x, unsigned char y );

void engine_level_manager_init_level()
{
	struct_level_object *lo = &global_level_object;
	unsigned char idx, row, col;

	// Initialize 14x14 maze.
	for( row = 0; row < MAZE_ROWS; row++ )
	{
		for( col = 0; col < MAZE_COLS; col++ )
		{
			idx = row * MAZE_COLS + col;

			lo->drawtiles_array[ idx ] = tile_type_blank;
			lo->collision_array[ idx ] = coll_type_empty;
		}
	}

	// Calculate 12x12 outside tree border.
	for( col = 0; col < TREE_COLS; col++ )
	{
		idx = MAZE_ROWS * 1 + (col + 1);
		lo->drawtiles_array[ idx ] = tile_type_trees;
		lo->collision_array[ idx ] = coll_type_block;

		idx = MAZE_ROWS * ( MAZE_ROWS - 2 ) + ( col + 1 );
		lo->drawtiles_array[ idx ] = tile_type_trees;
		lo->collision_array[ idx ] = coll_type_block;
	}
	for( row = 1; row < TREE_ROWS - 1; row++ )
	{
		idx = ( row + 1 ) * MAZE_COLS + 1;
		lo->drawtiles_array[ idx ] = tile_type_trees;
		lo->collision_array[ idx ] = coll_type_block;

		idx = (row + 1) * MAZE_COLS + ( MAZE_COLS - 2 );
		lo->drawtiles_array[ idx ] = tile_type_trees;
		lo->collision_array[ idx ] = coll_type_block;
	}
}

void engine_level_manager_load_level( const unsigned char world, const unsigned char round )
{
	unsigned char halve;
	unsigned char level;
	unsigned char index;

	halve = TOT_WORLDS / 2 * MAX_ROUNDS;
	level = world * MAX_ROUNDS + round;
	index = 0;

	if( level >= halve )
	{
		index = level - halve;
	}
	else
	{
		index = level;
	}

	if( level < halve )
	{
		const unsigned char *data = levelAAdata[ index ];
		const unsigned char bank = levelAAbank[ index ];
		const unsigned char size = levelAAsize[ index ];
		load_level( data, bank, size );
	}
	else
	{
		const unsigned char *data = levelBBdata[ index ];
		const unsigned char bank = levelBBbank[ index ];
		const unsigned char size = levelBBsize[ index ];
		load_level( data, bank, size );
	}
}

void engine_level_manager_draw_level()
{
	struct_level_object *lo = &global_level_object;
	unsigned char row, col;

	for( row = 0; row < MAX_ROWS; row++ )
	{
		for( col = 0; col < MAX_COLS; col++ )
		{
			draw_tiles( col, row );
		}
	}
}

// Assumes call to draw 12x12 i.e. include tree border.
//void engine_level_manager_draw_level_12()
//{
//	struct_level_object *lo = &global_level_object;
//	unsigned char row, col;
//
//	for( row = 0; row < TREE_ROWS; row++ )
//	{
//		for( col = 0; col < TREE_COLS; col++ )
//		{
//			draw_tiles_12( col, row );
//		}
//	}
//}

static void load_level( const unsigned char *data, const unsigned char bank, const unsigned char size )
{
	struct_level_object *lo = &global_level_object;

	const unsigned char *o = data;
	unsigned char row, col;
	unsigned char tile_data;

	unsigned int idx;
	unsigned char tile_type;
	unsigned char coll_type;

	lo->load_cols = size / MAX_ROWS;
	lo->draw_cols = lo->load_cols - CRLF;

	lo->candyCount = 0;
	lo->bonusCount = 0;

	devkit_SMS_mapROMBank( bank );
	for( row = 0; row < MAX_ROWS; row++ )
	{
		for( col = 0; col < lo->load_cols; col++ )
		{
			tile_data = *o;
			if( !( tile_data == CR || tile_data == LF ) )
			{
				engine_tile_manager_load_tile( &tile_type, tile_data );

				idx = ( row + 2 ) * MAZE_COLS + ( col + 2 );

				lo->drawtiles_array[ idx ] = tile_type;
				
				if( tile_type_candy == tile_type )
				{
					lo->candyCount++;
				}
				if( tile_type_bonusA == tile_type || tile_type_bonusB == tile_type || tile_type_bonusC == tile_type || tile_type_bonusD == tile_type )
				{
					lo->bonusCount++;
				}

				// TODO read from game object. 
				engine_tile_manager_load_coll( &coll_type, tile_data );
				lo->collision_array[ idx ] = coll_type;
			}

			o++;
		}
	}
}

static void draw_tiles( unsigned char x, unsigned char y )
{
	struct_level_object *lo = &global_level_object;
	unsigned char tile;
	unsigned int idx;

	idx = ( y + 2 ) * MAZE_COLS + ( x + 2 );
	tile = lo->drawtiles_array[ idx ];

	engine_tile_manager_draw_tile( tile, SCREEN_TILE_LEFT + ( x + 1 ) * 2, ( y + 1 ) * 2 );
}

// Assumes call to draw 12x12 i.e. include tree border.
//static void draw_tiles_12( unsigned char x, unsigned char y )
//{
//	struct_level_object *lo = &global_level_object;
//	unsigned char tile;
//	unsigned int idx;
//
//	idx = ( y + 1 ) * MAZE_COLS + ( x + 1 );
//	tile = lo->drawtiles_array[ idx ];
//
//	engine_tile_manager_draw_tile( tile, SCREEN_TILE_LEFT + x * 2, y * 2 );
//}