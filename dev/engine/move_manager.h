#ifndef _MOVE_MANAGER_H_
#define _MOVE_MANAGER_H_

#include "..\object\move_object.h"

void engine_move_manager_init();
void engine_move_manager_load();
void engine_move_manager_update();

unsigned char engine_move_manager_opposite_direction( unsigned char direction);
unsigned char engine_gamer_manager_actor_direction( unsigned char direction );

// Global variable.
//extern struct_move_object global_move_object;

#endif//_MOVE_MANAGER_H_