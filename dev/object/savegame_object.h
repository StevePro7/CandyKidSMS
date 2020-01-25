#ifndef _SAVEGAME_OBJECT_H_
#define _SAVEGAME_OBJECT_H_

#include "..\engine\global_manager.h"

// Reference: http://www.smspower.org/forums/16013-DevkitSMSSMSlibMissingRequestingFeatures#91899
typedef struct tag_struct_savegame_object
{
	unsigned long Magic;
	unsigned char save_tree_type;
	unsigned char save_exit_type;
	unsigned char save_world_no;
	unsigned char save_level_no;
	unsigned char save_padding[ 8 ];

	unsigned char frames[ MAX_COMMANDS ];
	unsigned char commands[ MAX_COMMANDS ];
	unsigned int args[ MAX_COMMANDS ];

	unsigned char terminal;

} struct_savegame_object;

#endif//_SAVEGAME_OBJECT_H_