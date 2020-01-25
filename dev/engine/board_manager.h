#ifndef _BOARD_MANAGER_H_
#define _BOARD_MANAGER_H_

// Kid home	2, 2
// Pro home	9, 9
// Adi home	2, 9
// Suz home	9, 2
#define KID_HOME_X	2
#define KID_HOME_Y	2
#define PRO_HOME_X	9
#define PRO_HOME_Y	9
#define ADI_HOME_X	2
#define ADI_HOME_Y	9
#define SUZ_HOME_X	9
#define SUZ_HOME_Y	2

#include "..\object\board_object.h"

// Global variable.
extern struct_board_object global_board_object;

void engine_board_manager_init();
void engine_board_manager_set_exit_type( unsigned char exit_type );
void engine_board_manager_set_tree_type( unsigned char tree_type );
void engine_board_manager_draw_edge();

#endif//_BOARD_MANAGER_H_