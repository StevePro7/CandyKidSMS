#ifndef _BOARD_MANAGER_H_
#define _BOARD_MANAGER_H_

#include "..\object\board_object.h"

// Global variable.
extern struct_board_object global_board_object;

void engine_board_manager_init();
void engine_board_manager_set_exit_type( unsigned char exit_type );
void engine_board_manager_set_tree_type( unsigned char tree_type );

void engine_board_manager_draw_full();
void engine_board_manager_draw_exit();
void engine_board_manager_main_full();
void engine_board_manager_main_exit();
void engine_board_manager_side_tile();

// TODO - delete!!
void engine_board_manager_debugger();

#endif//_BOARD_MANAGER_H_