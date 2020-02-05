#ifndef _ENEMY_OBJECT_H_
#define _ENEMY_OBJECT_H_

#include "..\engine\global_manager.h"

typedef struct tag_struct_enemy_object
{
	unsigned char posnX;		// PositionX during movement.
	unsigned char posnY;		// PositionY during movement.
	unsigned char homeX;		// Home tileX on all restart.
	unsigned char homeY;		// Home tileY on all restart.
	unsigned char homeZ;		// Home tile stored as R x C.
	unsigned char tileX;		// Posn tileX on enemy stops. 
	unsigned char tileY;		// Posn tileY on enemy stops.
	unsigned char tileZ;		// Posn tileY on enemy stops.
	unsigned char delay;
	unsigned char timer;
	unsigned char delta;
	unsigned char total;
	unsigned char speed;
	unsigned char mover;
	unsigned char prev_move;	// Previous direction moved.
	unsigned char direction;	// Current  direction moved.
	unsigned char lifecycle;
	unsigned int image;
	unsigned char frame;
	unsigned int calcd;
	unsigned char images[ NUM_ENTITY_IMAGE ][ NUM_ENTITY_FRAME ];

} struct_enemy_object;

#endif//_ENEMY_OBJECT_H_