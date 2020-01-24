#include "tile_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\gfx.h"
#include <stdlib.h>

#define BASE_TILES_OFFSET	26
#define BASE_CANDY_OFFSET	52
#define BASE_DEATH_OFFSET	22
#define BASE_GAMER_OFFSET	20

static void draw_tile( unsigned char offset, unsigned char x, unsigned char y );

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

static void draw_tile( unsigned char offset, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = game_tiles__tilemap__bin;

	devkit_SMS_setNextTileatXY( x + 0, y + 0 );	devkit_SMS_setTile( *pnt + offset + 0 );
	devkit_SMS_setNextTileatXY( x + 1, y + 0 );	devkit_SMS_setTile( *pnt + offset + 1 );
	devkit_SMS_setNextTileatXY( x + 0, y + 1 );	devkit_SMS_setTile( *pnt + offset + BASE_TILES_OFFSET + 0 );
	devkit_SMS_setNextTileatXY( x + 1, y + 1 );	devkit_SMS_setTile( *pnt + offset + BASE_TILES_OFFSET + 1 );
}