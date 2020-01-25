#include "save_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\command_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\storage_manager.h"
#include "..\engine\tile_manager.h"

//static void draw_trees();

void screen_save_screen_load()
{
	engine_board_manager_init();
	engine_gamer_manager_init( KID_HOME_X, KID_HOME_Y );

	engine_font_manager_draw_text( "SAVE SCREEN!!!!", 4, 1 );
}

void screen_save_screen_update( unsigned char *screen_type )
{
	engine_gamer_manager_draw();
	//struct_board_object *bo = &global_board_object;
	//unsigned char input;
	////unsigned int* frames;

	//input = engine_input_manager_hold_left();
	//if( input )
	//{
	//	engine_board_manager_set_exit_type( 1 - bo->save_exit_type );
	//	draw_trees();
	//}
	//input = engine_input_manager_hold_right();
	//if( input )
	//{
	//	engine_board_manager_set_tree_type( 1 - bo->save_tree_type );
	//	draw_trees();
	//}

	//input = engine_input_manager_hold_fire1();
	//if( input )
	//{
	//	engine_font_manager_draw_text( "SAVING....", 10, 20 );
	//	engine_storage_manager_write();
	//}

	*screen_type = screen_type_save;
}


//static void draw_trees()
//{
//	struct_board_object *bo = &global_board_object;
//
//	unsigned char tree_type = bo->save_tree_type;
//	unsigned char exit_type = bo->save_exit_type;
//
//	engine_font_manager_draw_data( tree_type, 12, 12 );
//	engine_font_manager_draw_data( exit_type, 12, 14 );
//
//	engine_tile_manager_draw_tree( tree_type, 10, 8 );
//	engine_tile_manager_draw_tree( tree_type, 16, 8 );
//
//	if( exit_type_closed == exit_type )
//	{
//		engine_tile_manager_draw_tree( tree_type, 12, 8 );
//		engine_tile_manager_draw_tree( tree_type, 14, 8 );
//	}
//	else
//	{
//		engine_tile_manager_draw_blank( 12, 8 );
//		engine_tile_manager_draw_blank( 14, 8 );
//	}
//}