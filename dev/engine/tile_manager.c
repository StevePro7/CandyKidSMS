#include "tile_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "..\banks\bank5.h"
#include "..\devkit\_sms_manager.h"
#include "..\gfx.h"
#include <stdlib.h>

#define BASE_TILES_OFFSET	26
#define BASE_BLOCK_OFFSET	12
#define BASE_CANDY_OFFSET	52
#define BASE_DEATH_OFFSET	22
#define BASE_GAMER_OFFSET	20

#define MAIN_CANDY_OFFSET	12
#define MAIN_GAMER_OFFSET	24

static void draw_tile( unsigned char offset, unsigned char x, unsigned char y );
static void draw_tile_priority( unsigned char offset, unsigned char x, unsigned char y );
static void main_tile( unsigned char offset, unsigned char x, unsigned char y );

void engine_tile_manager_load_tile( unsigned char *tile_type, unsigned char tile_data )
{
	if( '1' == tile_data )
	{
		*tile_type = tile_type_trees;
		return;
	}
	if( '2' == tile_data )
	{
		*tile_type = tile_type_candy;
		return;
	}
	if( '3' == tile_data )
	{
		*tile_type = tile_type_bonusA;
		return;
	}
	if( '4' == tile_data )
	{
		*tile_type = tile_type_bonusB;
		return;
	}
	if( '5' == tile_data )
	{
		*tile_type = tile_type_bonusC;
		return;
	}
	if( '6' == tile_data )
	{
		*tile_type = tile_type_bonusD;
		return;
	}

	*tile_type = tile_type_blank;
}

void engine_tile_manager_load_coll( unsigned char *coll_type, unsigned char tile_data )
{
	if( '1' == tile_data )
	{
		*coll_type = coll_type_block;
		return;
	}

	*coll_type = coll_type_empty;
}

// TODO rename this as is too generic!
void engine_tile_manager_draw_tile( unsigned char index, unsigned char x, unsigned char y )
{
	engine_tile_manager_draw_blank( x, y );

	if( tile_type_trees == index )
	{
		engine_tile_manager_draw_trees( tree_type_avoid, x, y );			// TODO don't hardcode here - get from board manager
	}
	else if( index >= tile_type_bonusA  && index <= tile_type_bonusD )
	{
		engine_tile_manager_draw_bonus( index, 1, x, y );
	}
	else if( tile_type_candy == index )
	{
		unsigned char type = 0;
		//while( 1 )
		//{
		type = rand() % MAX_BLOCK_TILES;				// TODO pre-calc this then render
														//if( type == 0 )
														//{
														//	break;
														//}
														//}

		engine_tile_manager_draw_candy( type, x, y );
	}
}

void engine_tile_manager_draw_blank( unsigned char x, unsigned char y )
{
	engine_font_manager_draw_char( ' ', x + 0, y + 0 );
	engine_font_manager_draw_char( ' ', x + 1, y + 0 );
	engine_font_manager_draw_char( ' ', x + 0, y + 1 );
	engine_font_manager_draw_char( ' ', x + 1, y + 1 );
}

void engine_tile_manager_draw_trees( unsigned char type, unsigned char x, unsigned char y )
{
	unsigned char offset = type * 2;
	draw_tile( offset, x, y );
}

void engine_tile_manager_draw_candy( unsigned char type, unsigned char x, unsigned char y )
{
	unsigned char offset = type * 2 + BASE_CANDY_OFFSET;
	draw_tile( offset, x, y );
}

void engine_tile_manager_draw_bonus( unsigned char type, unsigned char multiplier, unsigned char x, unsigned char y )
{
	unsigned char offset = ( type - 1 ) * 2;
	offset += ( multiplier - 1 ) * 8;
	draw_tile( offset, x, y );
}

void engine_tile_manager_draw_death( unsigned char type, unsigned char x, unsigned char y )
{
	unsigned char offset = type * 2 + BASE_DEATH_OFFSET;
	draw_tile( offset, x, y );
}

void engine_tile_manager_draw_gamer( unsigned char x, unsigned char y )
{
	unsigned char offset = BASE_GAMER_OFFSET;
	draw_tile( offset, x, y );
}

void engine_tile_manager_draw_sides( unsigned char x, unsigned char y )
{
	unsigned char offset = BASE_BLOCK_OFFSET * 2 + BASE_CANDY_OFFSET;
	draw_tile_priority( offset, x, y );
}

// Methods used for this main title screen.
void engine_tile_manager_main_title( unsigned char x, unsigned char y )
{
	const unsigned int *pnt = ( const unsigned int * ) main_tiles__tilemap__bin;

	unsigned char i;
	unsigned char j;

	// CANDY KID title is 26 cols * 4 rows of 8x8 tiles.
	for( j = 2; j < 6; j++ )
	{
		for( i = 0; i < 26; i++ )
		{
			devkit_SMS_setNextTileatXY( SCREEN_TILE_LEFT + x + i, y + ( j - 2 ) );
			devkit_SMS_setTile( *pnt + j * 26 + i );
		}
	}
}
void engine_tile_manager_main_trees( unsigned char type, unsigned char x, unsigned char y )
{
	unsigned char offset = type * 2;
	draw_tile( offset, x, y );
}
void engine_tile_manager_main_candy( unsigned char type, unsigned char x, unsigned char y )
{
	unsigned char offset = type * 2 + MAIN_CANDY_OFFSET;
	draw_tile( offset, x, y );
}
void engine_tile_manager_main_bonus( unsigned char type, unsigned char x, unsigned char y )
{
	unsigned char offset = ( type - 1 ) * 2;
	draw_tile( offset, x, y );
}
void engine_tile_manager_main_gamer( unsigned char x, unsigned char y )
{
	unsigned char offset = MAIN_GAMER_OFFSET;
	draw_tile( offset, x, y );
}

static void draw_tile( unsigned char offset, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = game_tiles__tilemap__bin;

	devkit_SMS_setNextTileatXY( x + 0, y + 0 );	devkit_SMS_setTile( *pnt + offset + 0 );
	devkit_SMS_setNextTileatXY( x + 1, y + 0 );	devkit_SMS_setTile( *pnt + offset + 1 );
	devkit_SMS_setNextTileatXY( x + 0, y + 1 );	devkit_SMS_setTile( *pnt + offset + BASE_TILES_OFFSET + 0 );
	devkit_SMS_setNextTileatXY( x + 1, y + 1 );	devkit_SMS_setTile( *pnt + offset + BASE_TILES_OFFSET + 1 );
}

static void draw_tile_priority( unsigned char offset, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = game_tiles__tilemap__bin;

	devkit_SMS_setNextTileatXY( x + 0, y + 0 );	devkit_SMS_setTilePriority( *pnt + offset + 0 );
	devkit_SMS_setNextTileatXY( x + 1, y + 0 );	devkit_SMS_setTilePriority( *pnt + offset + 1 );
	devkit_SMS_setNextTileatXY( x + 0, y + 1 );	devkit_SMS_setTilePriority( *pnt + offset + BASE_TILES_OFFSET + 0 );
	devkit_SMS_setNextTileatXY( x + 1, y + 1 );	devkit_SMS_setTilePriority( *pnt + offset + BASE_TILES_OFFSET + 1 );
}

static void main_tile( unsigned char offset, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = main_tiles__tilemap__bin;

	devkit_SMS_setNextTileatXY( x + 0, y + 0 );	devkit_SMS_setTile( *pnt + offset + 0 );
	devkit_SMS_setNextTileatXY( x + 1, y + 0 );	devkit_SMS_setTile( *pnt + offset + 1 );
	devkit_SMS_setNextTileatXY( x + 0, y + 1 );	devkit_SMS_setTile( *pnt + offset + BASE_TILES_OFFSET + 0 );
	devkit_SMS_setNextTileatXY( x + 1, y + 1 );	devkit_SMS_setTile( *pnt + offset + BASE_TILES_OFFSET + 1 );
}