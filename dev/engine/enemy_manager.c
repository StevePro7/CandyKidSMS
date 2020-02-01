#include "enemy_manager.h"
#include "board_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "sprite_manager.h"

#define SPRITE_TILES_ENEMY	256 + 48

// Global variables.
struct_enemy_object global_enemy_objects[ MAX_ENEMIES ];

static void calcd_frame( unsigned char enemy );
static void calcd_spots( unsigned char enemy );

// Methods.
void engine_enemy_manager_init()
{
	struct_enemy_object *eo;
	unsigned char images[ NUM_ENTITY_IMAGE * NUM_ENTITY_FRAME * MAX_ENEMIES ] =
	{
		0, 2, 4, 12,		// Pro images.
		14, 16, 24, 26,		// Adi images.
		28, 36, 38, 40,		// Suz images.
	};

	unsigned char frame;
	unsigned char homeX;
	unsigned char homeY;

	unsigned char idx;
	for( idx = 0; idx < MAX_ENEMIES; idx++ )
	{
		eo = &global_enemy_objects[ idx ];

		homeX = board_homeX[ idx ];
		homeY = board_homeY[ idx ];

		eo->homeX = homeX;
		eo->homeY = homeY;
		eo->tileX = homeX;
		eo->tileY = homeY;
		eo->delay = 8;		// TODO hardcoded - inject!
		eo->timer = 0;
		eo->delta = 0;
		eo->total = 0;
		eo->speed = 1;		// TODO hardcoded - inject!

		eo->direction = direction_type_none;
		eo->lifecycle = lifecycle_type_idle;

		eo->image = 0;
		eo->frame = 0;

		frame = idx * NUM_ENTITY_IMAGE * NUM_ENTITY_FRAME + 0;

		eo->images[ 0 ][ 0 ] = images[ frame + 0 ];
		eo->images[ 0 ][ 1 ] = images[ frame + 1 ];
		eo->images[ 1 ][ 0 ] = images[ frame + 2 ];
		eo->images[ 1 ][ 1 ] = images[ frame + 3 ];

		/*
		image = images[ frame + 0 ];
		eo->images[ 0 ][ 0 ] = image;

		image = images[ frame + 1 ];
		eo->images[ 0 ][ 1 ] = image;

		image = images[ frame + 2 ];
		eo->images[ 1 ][ 0 ] = image;

		image = images[ frame + 3 ];
		eo->images[ 1 ][ 1 ] = image;
		*/
		calcd_frame( idx );
		calcd_spots( idx );
	}
}

//void engine_enemy_manager_load()
//{
//	// TODO hardcoded - inject!
//	struct_enemy_object *eo = &global_enemy_objects[ actor_type_pro ];
//	eo->posnX = 144;
//	eo->posnY = 144;
//	eo->tileX = 9;
//	eo->tileY = 9;
//}

void engine_enemy_manager_update( unsigned char enemy )
{
	struct_enemy_object *eo = &global_enemy_objects[ enemy ];
	if( lifecycle_type_move != eo->lifecycle )
	{
		return;
	}

	eo->timer++;
	if( eo->timer < eo->delay )
	{
		return;
	}

	eo->timer = 0;
	eo->delta += eo->speed;
	eo->total += eo->speed;

	// Update position.
	if( direction_type_upxx == eo->direction )
	{
		eo->posnY -= eo->speed;
	}
	/*else if( direction_type_down == eo->direction )
	{
		eo->posnY += eo->speed;
	}
	else if( direction_type_left == eo->direction )
	{
		eo->posnX -= eo->speed;
	}
	else if( direction_type_rght == eo->direction )
	{
		eo->posnX += eo->speed;
	}*/

	// Update lifecycle.
	if( eo->total >= TILE_SIZE )
	{
		if( direction_type_upxx == eo->direction )
		{
			eo->tileY--;
		}
		/*else if( direction_type_down == eo->direction )
		{
			eo->tileY++;
		}
		else if( direction_type_left == eo->direction )
		{
			eo->tileX--;
		}
		else if( direction_type_rght == eo->direction )
		{
			eo->tileX++;
		}*/

		calcd_spots( enemy );

		eo->lifecycle = lifecycle_type_idle;
		eo->delta = 0;
		eo->total = 0;
	}

	if( eo->delta > TILE_HALF )
	{
		eo->frame = 1 - eo->frame;
		eo->delta = 0;
		calcd_frame( enemy );
	}
}

void engine_enemy_manager_draw()
{
	struct_enemy_object *eo;
	unsigned char enemy;
	//for( idx = 0; idx < MAX_ENEMIES; idx++ )
	//TODO revert to draw all enemies
	for( enemy = 0; enemy < MAX_ENEMIES; enemy++ )
	{
		eo = &global_enemy_objects[ enemy ];
		engine_sprite_manager_draw_entity( eo->posnX, eo->posnY, eo->calcd );
	}
}

void engine_enemy_manager_move( unsigned char enemy, unsigned char direction )
{
	struct_enemy_object *eo = &global_enemy_objects[ enemy ];
	eo->direction = direction;
	eo->lifecycle = lifecycle_type_move;
	eo->frame = 1;
	calcd_frame( enemy );
}

void engine_enemy_manager_stop( unsigned char enemy )
{
	struct_enemy_object *eo = &global_enemy_objects[ enemy ];
	eo->direction = direction_type_none;
	eo->frame = 0;
	calcd_frame( enemy );
}

static void calcd_frame( unsigned char enemy )
{
	struct_enemy_object *eo = &global_enemy_objects[ enemy ];
	//eo->calcd = SPRITE_TILES_ENEMY + eo->image * 8 + eo->frame * 4;
	eo->calcd = SPRITE_TILES_ENEMY + eo->images[ eo->image ][ eo->frame ];
}
static void calcd_spots( unsigned char enemy )
{
	struct_enemy_object *eo = &global_enemy_objects[ enemy ];
	struct_board_object *bo = &global_board_object;
	eo->posnX = bo->posnX[ eo->tileX ];
	eo->posnY = bo->posnY[ eo->tileY ];
}