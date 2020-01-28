#include "load_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\hack_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\global_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\level_manager.h"
#include "..\engine\sprite_manager.h"
#include "..\engine\tile_manager.h"

void screen_load_screen_load()
{
	struct_hack_object *ho = &global_hack_object;

	//engine_font_manager_draw_text( "LOAD SCREEN!!", 4, 1 );

	engine_board_manager_init();
	engine_gamer_manager_init();
	engine_enemy_manager_init();

	//engine_board_manager_draw_full();
	//engine_board_manager_draw_edge();
	engine_board_manager_debugger();

	engine_level_manager_init_board();
	engine_level_manager_init_exits();

	engine_level_manager_load_level( ho->hack_world, ho->hack_round );
	engine_level_manager_draw_level();

	engine_font_manager_draw_data( ho->hack_world + 1, 31, 0 );
	engine_font_manager_draw_data( ho->hack_round + 1, 31, 1 );
}

void screen_load_screen_update( unsigned char *screen_type )
{
	struct_hack_object *ho = &global_hack_object;
	unsigned char input;
	unsigned char check;
	check = 0;

	engine_gamer_manager_draw();
	engine_enemy_manager_draw();

	input = engine_input_manager_hold_left();
	if( input )
	{
		check = 1;
		if( ho->hack_round == 0 )
		{
			ho->hack_round = MAX_ROUNDS - 1;
		}
		else
		{
			ho->hack_round--;
		}
	}

	input = engine_input_manager_hold_up();
	if( input )
	{
		check = 1;
		if( ho->hack_world == 0 )
		{
			ho->hack_world = MAX_WORLDS - 1;
		}
		else
		{
			ho->hack_world--;
		}
	}

	input = engine_input_manager_hold_right();
	if( input )
	{
		check = 1;
		ho->hack_round++;
		if( ho->hack_round >= MAX_ROUNDS )
		{
			ho->hack_round = 0;
		}
	}

	input = engine_input_manager_hold_down();
	if( input )
	{
		check = 1;
		ho->hack_world++;
		if( ho->hack_world >= MAX_WORLDS )
		{
			ho->hack_world = 0;
		}
	}

	if( check )
	{
		engine_level_manager_load_level( ho->hack_world, ho->hack_round );
		engine_level_manager_draw_level();

		engine_font_manager_draw_data( ho->hack_world + 1, 31, 0 );
		engine_font_manager_draw_data( ho->hack_round + 1, 31, 1 );
	}

	*screen_type = screen_type_load;
}