#ifndef _ENEMY_OBJECT_H_
#define _ENEMY_OBJECT_H_

#include "..\engine\global_manager.h"

typedef struct tag_struct_enemy_object
{
	unsigned char board;		// Board index for home spot.
	unsigned char posnX;		// PositionX during movement.
	unsigned char posnY;		// PositionY during movement.
	unsigned char homeX;		// Home tileX on all restart.
	unsigned char homeY;		// Home tileY on all restart.
	unsigned char tileX;		// Base tileX on enemy stops. 
	unsigned char tileY;		// Base tileY on enemy stops.
	unsigned char delay;
	unsigned char timer;
	unsigned char delta;
	unsigned char total;
	unsigned char speed;
	unsigned char mover;
	unsigned char direction;
	unsigned char lifecycle;
	unsigned int image;
	unsigned char frame;
	unsigned int calcd;
	unsigned char images[ NUM_ENTITY_IMAGE ][ NUM_ENTITY_FRAME ];

} struct_enemy_object;

#endif//_ENEMY_OBJECT_H_