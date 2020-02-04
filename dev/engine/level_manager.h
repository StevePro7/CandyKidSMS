#ifndef _LEVEL_MANAGER_H_
#define _LEVEL_MANAGER_H_

#include "..\object\level_object.h"

// Global variable.
extern struct_level_object global_level_object;

void engine_level_manager_init_board();
void engine_level_manager_init_exits();
void engine_level_manager_load_level( const unsigned char world, const unsigned char round );
void engine_level_manager_draw_level();

#endif//_LEVEL_MANAGER_H_