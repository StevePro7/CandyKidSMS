#include "intro_screen.h"
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

void screen_intro_screen_load()
{
	engine_font_manager_draw_text( "INTRO  SCREEN..!!", 4, 2 );
	//draw_items();

	engine_board_manager_init();
	// TODO allow for SCREEN_TILE_LEFT
	//engine_tile_manager_main_title(4, 2);
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_intro;
}

static void draw_items()
{
	engine_tile_manager_main_trees( tree_type_avoid, 4, 4 );
	engine_tile_manager_main_trees( tree_type_death, 6, 4 );

	engine_tile_manager_main_bonus( tile_type_bonusA, 10, 6 );
	engine_tile_manager_main_bonus( tile_type_bonusB, 14, 6 );
	engine_tile_manager_main_bonus( tile_type_bonusC, 18, 6 );
	engine_tile_manager_main_bonus( tile_type_bonusD, 22, 6 );

	engine_tile_manager_main_candy( 0, 4, 18 );
	engine_tile_manager_main_candy( 1, 6, 18 );
	engine_tile_manager_main_candy( 2, 8, 18 );
	engine_tile_manager_main_candy( 3, 10, 18 );
	engine_tile_manager_main_candy( 4, 12, 18 );
	engine_tile_manager_main_candy( 5, 14, 18 );

	engine_tile_manager_main_gamer( 16, 16 );
}