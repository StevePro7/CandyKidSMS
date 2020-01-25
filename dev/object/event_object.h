#ifndef _EVENT_OBJECT_H_
#define _EVENT_OBJECT_H_

#include "..\engine\global_manager.h"

typedef struct tag_struct_event_object
{
	unsigned char event_index;
	unsigned char event_type[ 10 ];
	unsigned char event_args[ 10 ];


	unsigned int move1Index;
	//unsigned int move2Index;
	//unsigned int speedIndex;

	unsigned char move1Frame[ MAX_MOVES_COUNT ];
	unsigned char move1Event[ MAX_MOVES_COUNT ];
	//unsigned char move2Frame[ MAX_MOVES_COUNT ];
	//unsigned char move2Event[ MAX_MOVES_COUNT ];

	//unsigned char speedFrame[ MAX_SPEED_COUNT ];

} struct_event_object;

#endif//_EVENT_OBJECT_H_