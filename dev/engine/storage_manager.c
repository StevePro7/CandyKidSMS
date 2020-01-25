#include "storage_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\engine\board_manager.h"
#include "..\engine\command_manager.h"
#include "..\engine\font_manager.h"

#define MAGIC			0xACE0B004

// Global variable.
struct_savegame_object global_savegame_object;

unsigned char engine_storage_manager_available()
{
	struct_savegame_object *savegame = ( struct_savegame_object* ) ( devkit_SMS_SRAM() );
	unsigned char foundMagic;

	devkit_SMS_enableSRAM();
	foundMagic = MAGIC == savegame->Magic;
	devkit_SMS_disableSRAM();
	return foundMagic;
}

void engine_storage_manager_read()
{
	struct_savegame_object *savegame = ( struct_savegame_object* ) ( devkit_SMS_SRAM() );
	unsigned char world_no;
	unsigned char level_no;
	unsigned char padding[ 8 ];
	unsigned char idx;

	devkit_SMS_enableSRAM();
	engine_board_manager_set_tree_type( savegame->save_tree_type );
	engine_board_manager_set_exit_type( savegame->save_exit_type );

	world_no = savegame->save_world_no;
	level_no = savegame->save_level_no;
	for( idx = 0; idx < 8; idx++ )
	{
		padding[ idx ] = savegame->save_padding[ idx ];
	}

	engine_command_manager_load( savegame->frames, savegame->commands, savegame->args );
	devkit_SMS_disableSRAM();
}

void engine_storage_manager_write()
{
	struct_savegame_object *savegame = ( struct_savegame_object* ) ( devkit_SMS_SRAM() );
	struct_board_object *bo = &global_board_object;
	struct_command_object *co = &global_command_object;
	unsigned int idx;

	devkit_SMS_enableSRAM();
	savegame->Magic = MAGIC;

	savegame->save_tree_type = bo->save_tree_type;
	savegame->save_exit_type = bo->save_exit_type;
	savegame->save_world_no = 7;//world_no
	savegame->save_level_no = 8;//level_no;
	for( idx = 0; idx < 8; idx++ )
	{
		savegame->save_padding[ idx ] = idx + 1;
	}

	// Commands.
	for( idx = 0; idx < MAX_COMMANDS; idx++ )
	{
		savegame->frames[ idx ] = co->frames[ idx ];
		savegame->commands[ idx ] = co->commands[ idx ];
		savegame->args[ idx ] = co->args[ idx ];
	}

	savegame->terminal = 0xFD;
	devkit_SMS_disableSRAM();
}