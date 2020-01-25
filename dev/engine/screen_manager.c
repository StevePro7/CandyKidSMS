#include "screen_manager.h"
#include "global_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "input_manager.h"
#include "sprite_manager.h"
#include "tile_manager.h"

static void( *load_method[ MAX_SCREEENS ] )( );
static void( *update_method[ MAX_SCREEENS ] )( unsigned char *screen_type );

static unsigned char curr_screen_type;
static unsigned char next_screen_type;

void engine_screen_manager_init( unsigned char open_screen_type )
{
	unsigned char idx;

	next_screen_type = open_screen_type;
	curr_screen_type = screen_type_none;

	engine_font_manager_draw_text( "HELLO WORLD!!", 2, 2 );

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
}

void engine_screen_manager_update()
{
	unsigned char death = 0;
	unsigned char input;
	engine_sprite_manager_draw_entity( 32, 64, 256 + 96 );

	input = engine_input_manager_move_fire1();
	if( input )
	{
		engine_font_manager_draw_text( "HELLO WORLD...!!", 2, 4 );
		death = 1;
	}

	engine_tile_manager_draw_death( death, 6, 8 );
}