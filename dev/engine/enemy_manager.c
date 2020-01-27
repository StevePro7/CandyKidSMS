#include "enemy_manager.h"
#include "board_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "sprite_manager.h"

#define SPRITE_TILES_PRO	256 + 48

// Global variables.
struct_enemy_object global_enemy_objects[ MAX_ENEMIES ];

static void calcd_frame( unsigned char index );
static void calcd_spots( unsigned char index );

// Methods.
void engine_enemy_manager_init( unsigned char *homeX, unsigned char *homeY )
{
	// Pro images.
	//unsigned char images[] = { 0, 2, 4, 12 };
	// Adi images.
	//unsigned char images[] = { 14, 16, 24, 26 };
	// Suz images.
	//unsigned char images[] = { 28, 36, 38, 40 };


	struct_enemy_object *eo;
	unsigned char idx;
	for( idx = 0; idx < MAX_ENEMIES; idx++ )
	{
		eo = &global_enemy_objects[ idx ];
		eo->homeX = homeX[ idx ];
		eo->homeY = homeY[ idx ];
		eo->tileX = homeX[ idx ];
		eo->tileY = homeY[ idx ];
		//eo->posnX = 0;
		//eo->posnY = 0;
		eo->tileX = 0;
		eo->tileY = 0;
		eo->delay = 10;		// TODO hardcoded - inject!
		eo->timer = 0;
		eo->delta = 0;
		eo->total = 0;
		eo->speed = 1;		// TODO hardcoded - inject!

		eo->direction = direction_type_none;
		eo->lifecycle = lifecycle_type_idle;

		eo->image = 0;
		eo->frame = 0;
		calcd_frame( idx );
		calcd_spots( idx );
	}
}

void engine_enemy_manager_load()
{
	// TODO hardcoded - inject!
	struct_enemy_object *eo = &global_enemy_objects[ actor_type_pro ];
	eo->posnX = 144;
	eo->posnY = 144;
	eo->tileX = 9;
	eo->tileY = 9;
}

void engine_enemy_manager_update()
{
	struct_enemy_object *eo = &global_enemy_objects[ actor_type_pro ];
	if( lifecycle_type_idle == eo->lifecycle )
	{
		return;
	}

	if( lifecycle_type_move == eo->lifecycle )
	{
		eo->timer++;
		if( eo->timer <= eo->delay )
		{
			return;
		}

		eo->timer = 0;
		eo->delta += eo->speed;
		eo->total += eo->speed;

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

			eo->posnX = eo->tileX * TILE_SIZE;
			eo->posnY = eo->tileY * TILE_SIZE;

			eo->direction = direction_type_none;
			eo->lifecycle = lifecycle_type_idle;
			eo->delta = 0;
			eo->total = 0;
		}

		if( eo->delta > TILE_HALF )
		{
			eo->frame = 1 - eo->frame;
			eo->delta = 0;
			calcd_frame( actor_type_pro );
		}

	}
}

void engine_enemy_manager_move( unsigned char index, unsigned char direction )
{
	struct_enemy_object *eo = &global_enemy_objects[ actor_type_pro ];
	eo->direction = direction;
	eo->lifecycle = lifecycle_type_move;
	eo->frame = 1;
	calcd_frame( index );
}

void engine_enemy_manager_draw()
{
	struct_enemy_object *eo;
	unsigned char idx;
	//for( idx = 0; idx < MAX_ENEMIES; idx++ )
	//TODO revert to draw all enemies
	for( idx = 0; idx < 1; idx++ )
	{
		eo = &global_enemy_objects[ idx ];
		engine_sprite_manager_draw_entity( eo->posnX, eo->posnY, eo->calcd );
	}
}

static void calcd_frame( unsigned char index )
{
	struct_enemy_object *eo = &global_enemy_objects[ index ];
	eo->calcd = SPRITE_TILES_PRO + eo->image * 8 + eo->frame * 4;
}
static void calcd_spots( unsigned char index )
{
	struct_enemy_object *eo = &global_enemy_objects[ index ];
	struct_board_object *bo = &global_board_object;
	eo->posnX = bo->posnX[ eo->tileX ];
	eo->posnY = bo->posnY[ eo->tileY ];
}