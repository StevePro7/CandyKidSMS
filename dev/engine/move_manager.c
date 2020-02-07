#include "move_manager.h"
#include "enum_manager.h"
#include "level_manager.h"
#include <stdlib.h>

// Global variable.
//struct_move_object global_move_object;

/*
unsigned char engine_move_manager_exec_direction()
{
	unsigned char deltaX, deltaY, plusX, minusY;
	unsigned char index;

	unsigned char srceX, srceY, destX, destY;
	srceX = 18;
	srceY = 11;

	destX = 27;
	destY = 30;


	index = 0;
	plusX = 0;
	minusY = 0;


	// Determine which directions...
	deltaX = 0;
	if( srceX > destX )
	{
		deltaX = srceX - destX;
	}
	else if( srceX < destX )
	{
		deltaX = destX - srceX;
		plusX = 1;
	}

	deltaY = 0;
	if( srceY > destY )
	{
		deltaY = srceY - destY;
		minusY = 1;
	}
	else if( srceY < destY )
	{
		deltaY = destY - srceY;
	}


	// Determine which direction index to use.
	if( deltaX > deltaY )
	{
		if( plusX )
		{
			index = minusY ? 0 : 1;
		}
		else
		{
			index = minusY ? 2 : 3;
		}
	}
	else
	{
		if( plusX )
		{
			index = minusY ? 4 : 5;
		}
		else
		{
			index = minusY ? 6 : 7;
		}
	}

	return index;
}
*/

unsigned char engine_move_manager_find_direction( unsigned char srceX, unsigned char srceY, unsigned char destX, unsigned char destY )
{
	unsigned char deltaX;
	unsigned char deltaY;
	unsigned char plusX;
	unsigned char minusY;
	unsigned char index;

	unsigned char sort;
	unsigned char half;
	unsigned char full;
	unsigned char byte;

	index = 0;
	plusX = 0;
	minusY = 0;

	// Determine which directions...
	deltaX = 0;
	if( srceX > destX )
	{
		deltaX = srceX - destX;
	}
	else if( srceX < destX )
	{
		deltaX = destX - srceX;
		plusX = 1;
	}

	deltaY = 0;
	if( srceY > destY )
	{
		deltaY = srceY - destY;
		minusY = 1;
	}
	else if( srceY < destY )
	{
		deltaY = destY - srceY;
	}


	// Determine which direction index to use.
	if( deltaX > deltaY )
	{
		if( plusX )
		{
			index = minusY ? 0 : 1;
			sort = 0;
		}
		else
		{
			index = minusY ? 2 : 3;
			sort = 1;
		}
	}
	else
	{
		if( plusX )
		{
			index = minusY ? 4 : 5;
			sort = 2;
		}
		else
		{
			index = minusY ? 6 : 7;
			sort = 3;
		}
	}

	half = minusY ? 0 : 1;

	// Upper nibble sets sort index.
	// Lower nibble sets half value.
	byte = ( half | ( sort << 4 ) );
	full = ( half | ( sort << 4 ) );
	return full;
}

void engine_move_manager_init()
{
	//unsigned char y = move_exec_direction[ 0 ][ 1 ];
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

unsigned char engine_move_manager_actor_direction( unsigned char direction )
{
	unsigned char loop;
	unsigned char time;

	// If actor already traveling in direction then return that direction,
	if( direction_type_none != direction )
	{
		return direction;
	}

	// Otherwise calculate random direction for further game code function.
	direction = 1;
	time = rand() % 4;

	// Algorithm will give 1, 2, 4, 8	that is : Up / Down / Left / Right.
	for( loop = 0; loop < time; loop++ )
	{
		direction *= 2;
	}

	return direction;
}