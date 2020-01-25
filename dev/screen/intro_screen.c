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
	engine_font_manager_draw_text( "INTRO  SCREEN!!", 4, 0 );
	draw_items();
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_intro;
}

static void draw_items()
{
}