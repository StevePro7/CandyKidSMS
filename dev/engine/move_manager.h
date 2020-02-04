#ifndef _MOVE_MANAGER_H_
#define _MOVE_MANAGER_H_

void engine_move_manager_init();
void engine_move_manager_load();
void engine_move_manager_update();

unsigned char engine_move_manager_opposite_direction( unsigned char direction);

#endif//_MOVE_MANAGER_H_