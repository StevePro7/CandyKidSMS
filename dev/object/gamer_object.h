#ifndef _GAMER_OBJECT_H_
#define _GAMER_OBJECT_H_

#include "..\engine\global_manager.h"

typedef struct tag_struct_gamer_object
{
	int posnX;					// PositionX during movement.
	int posnY;					// PositionY during movement.
	unsigned char homeX;		// Home tileX on all restart.
	unsigned char homeY;		// Home tileY on all restart.
	unsigned char homeZ;		// Home tile stored as R x C.
	unsigned char tileX;		// Posn tileX on enemy stops. 
	unsigned char tileY;		// Posn tileY on enemy stops.
	unsigned char tileZ;		// Posn tile stored as R x C.
	unsigned char delay;
	unsigned char timer;
	unsigned char delta;
	unsigned char total;
	unsigned char speed;
	unsigned char prev_move;	// Previous direction moved.
	unsigned char direction;	// Current  direction moved.
	unsigned char lifecycle;
	unsigned int image;
	unsigned char frame;
	unsigned int calcd;
	unsigned char images[ NUM_ENTITY_IMAGE ][ NUM_ENTITY_FRAME ];

} struct_gamer_object;

#endif//_GAMER_OBJECT_H_