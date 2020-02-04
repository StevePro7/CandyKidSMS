#ifndef _BOARD_OBJECT_H_
#define _BOARD_OBJECT_H_

#include "..\engine\global_manager.h"

typedef struct tag_struct_board_object
{
	unsigned char save_tree_type;
	unsigned char save_exit_type;
	
	unsigned char top;
	unsigned char bottom;
	unsigned char left;
	unsigned char right;
	unsigned char right2;

	int posnX[ MAZE_COLS ];
	int posnY[ MAZE_ROWS ];

} struct_board_object;

extern const unsigned char board_exitX[];
extern const unsigned char board_exitY[];

extern const unsigned char board_homeX[];
extern const unsigned char board_homeY[];
extern unsigned char	   board_homeZ[];

#endif//_BOARD_OBJECT_H_