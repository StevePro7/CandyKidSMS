#include "move_manager.h"
#include "enum_manager.h"
#include "level_manager.h"
#include <stdlib.h>

// Global variable.
//struct_move_object global_move_object;

void engine_move_manager_init()
{
	unsigned char y = move_exec_direction[ 0 ][ 1 ];
	unsigned char x = move_find_direction[ 10 ];
	
	/*struct_move_object *mo = &global_move_object;
	mo->find_direction[ 0 ][ 1 ] = direction_type_rght; mo->find_direction[ 0 ][ 1 ] = direction_type_rght; mo->find_direction[ 0 ][ 1 ] = direction_type_rght;
	{
		direction_type_rght, direction_type_upxx, direction_type_down, direction_type_left,
		direction_type_rght, direction_type_upxx, direction_type_down, direction_type_left,
		direction_type_rght, direction_type_upxx, direction_type_down, direction_type_left,
		direction_type_rght, direction_type_upxx, direction_type_down, direction_type_left,
		direction_type_rght, direction_type_upxx, direction_type_down, direction_type_left,
		direction_type_rght, direction_type_upxx, direction_type_down, direction_type_left,
		direction_type_rght, direction_type_upxx, direction_type_down, direction_type_left,
		direction_type_rght, direction_type_upxx, direction_type_down, direction_type_left,
	};*/
}

void engine_move_manager_load()
{
}

void engine_move_manager_update()
{
}

unsigned char engine_move_manager_opposite_direction( unsigned char direction )
{
	if( direction_type_left == direction )
	{
		return direction_type_rght;
	}
	else if( direction_type_rght == direction )
	{
		return direction_type_left;
	}
	else if( direction_type_upxx == direction )
	{
		return direction_type_down;
	}
	else if( direction_type_down == direction )
	{
		return direction_type_upxx;
	}

	return direction_type_none;
}

unsigned char engine_gamer_manager_actor_direction( unsigned char direction )
{
	unsigned char loop;
	unsigned char time;

	// If actor already traveling in direction return that direction,
	if( direction_type_none != direction )
	{
		return direction;
	}

	// Otherwise calculate random direction for further game code use.
	direction = 1;
	time = rand() % 4;
	for( loop = 0; loop < time; loop++ )
	{
		direction *= 2;
	}

	return direction;
}