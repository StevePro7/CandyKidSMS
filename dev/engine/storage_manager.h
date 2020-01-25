#ifndef _STORAGE_MANAGER_H_
#define _STORAGE_MANAGER_H_

#include "..\object\savegame_object.h"

// Global variable.
extern struct_savegame_object global_savegame_object;

unsigned char engine_storage_manager_available();
void engine_storage_manager_read();
void engine_storage_manager_write();

#endif//_STORAGE_MANAGER_H_