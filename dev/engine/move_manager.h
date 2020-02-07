#ifndef _MOVE_MANAGER_H_
#define _MOVE_MANAGER_H_

#include "..\object\move_object.h"

void engine_move_manager_init();
void engine_move_manager_load();
void engine_move_manager_update();

unsigned char engine_move_manager_opposite_direction( unsigned char direction);
unsigned char engine_move_manager_actor_direction( unsigned char direction );

unsigned char engine_move_manager_exec_direction();
unsigned char engine_move_manager_find_direction( unsigned char srceX, unsigned char srceY, unsigned char destX, unsigned char destY );

// Global variable.
//extern struct_move_object global_move_object;

#endif//_MOVE_MANAGER_H_