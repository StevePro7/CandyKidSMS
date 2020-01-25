#ifndef _BOARD_OBJECT_H_
#define _BOARD_OBJECT_H_

#include "..\engine\global_manager.h"

typedef struct tag_struct_board_object
{
	unsigned char save_tree_type;
	unsigned char save_exit_type;
	
	unsigned char posnX[ TREE_COLS ];
	unsigned char posnY[ TREE_ROWS ];

} struct_board_object;

#endif//_BOARD_OBJECT_H_