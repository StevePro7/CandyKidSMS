#include "move_manager.h"
#include "enum_manager.h"

void engine_move_manager_init()
{
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