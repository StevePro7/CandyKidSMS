#ifndef _GAMER_OBJECT_H_
#define _GAMER_OBJECT_H_

#include "..\engine\global_manager.h"

typedef struct tag_struct_gamer_object
{
	int posnX;
	int posnY;
	unsigned char homeX;
	unsigned char homeY;
	signed char tileX;
	signed char tileY;
	unsigned char delta;
	unsigned char total;
	unsigned char speed;
	unsigned char direction;
	unsigned char lifecycle;
	unsigned int image;
	unsigned char frame;
	unsigned int calcd;
	unsigned char images[ NUM_ENTITY_IMAGE ][ NUM_ENTITY_FRAME ];

} struct_gamer_object;

#endif//_GAMER_OBJECT_H_