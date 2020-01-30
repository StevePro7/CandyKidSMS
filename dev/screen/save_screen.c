#include "save_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\command_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\sprite_manager.h"
#include "..\engine\tile_manager.h"

static void draw_items();
static unsigned char x;

void screen_save_screen_load()
{
	engine_font_manager_draw_text( "SAVE SCREEN...!!", 4, 1 );
	draw_items();

	x = 128;
}

void screen_save_screen_update( unsigned char *screen_type )
{
	unsigned char death = 0;
	unsigned char input;
	engine_sprite_manager_draw_entity( x, 144, 256 + 96 );

	input = engine_input_manager_hold_right();
	if( input )
	{
		x++;
	}

	input = engine_input_manager_move_fire1();
	if( input )
	{
		engine_font_manager_draw_text( "HELLO WORLD...!!", 2, 4 );
		death = 1;
	}

	*screen_type = screen_type_save;
}

static void draw_items()
{
	unsigned char idx;

	engine_tile_manager_draw_trees( tree_type_avoid, 4, 4 );
	engine_tile_manager_draw_trees( tree_type_death, 6, 4 );

	engine_tile_manager_draw_bonus( tile_type_bonusA, 1, 10, 6 );
	engine_tile_manager_draw_bonus( tile_type_bonusB, 1, 14, 6 );
	engine_tile_manager_draw_bonus( tile_type_bonusC, 1, 18, 6 );
	engine_tile_manager_draw_bonus( tile_type_bonusD, 1, 22, 6 );

	engine_tile_manager_draw_bonus( tile_type_bonusA, 2, 10, 8 );
	engine_tile_manager_draw_bonus( tile_type_bonusB, 2, 14, 8 );
	engine_tile_manager_draw_bonus( tile_type_bonusC, 2, 18, 8 );
	engine_tile_manager_draw_bonus( tile_type_bonusD, 2, 22, 8 );

	engine_tile_manager_draw_gamer( 16, 16 );

	for( idx = 0; idx < MAX_BLOCK_TILES; idx++ )
	{
		engine_tile_manager_draw_candy( idx, idx * 2 + 2, 20 );
	}

	engine_tile_manager_draw_sides( 18, 18 );
}