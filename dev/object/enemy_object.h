#ifndef _ENEMY_OBJECT_H_
#define _ENEMY_OBJECT_H_

typedef struct tag_struct_enemy_object
{
	unsigned char posnX;
	unsigned char posnY;
	unsigned char homeX;
	unsigned char homeY;
	signed char tileX;
	signed char tileY;
	unsigned char delay;
	unsigned char timer;
	unsigned char delta;
	unsigned char total;
	unsigned char speed;
	unsigned char direction;
	unsigned char lifecycle;
	unsigned int image;
	unsigned char frame;
	unsigned int calcd;

} struct_enemy_object;

#endif//_ENEMY_OBJECT_H_