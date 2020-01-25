#ifndef _COMMAND_OBJECT_H_
#define _COMMAND_OBJECT_H_

#include "..\engine\global_manager.h"

typedef struct tag_struct_command_object
{
	unsigned char frames[ MAX_COMMANDS ];
	unsigned char commands[ MAX_COMMANDS ];
	unsigned int args[ MAX_COMMANDS ];

} struct_command_object;

#endif//_COMMAND_OBJECT_H_