#ifndef _FRAME_MANAGER_H_
#define _FRAME_MANAGER_H__

#include "..\object\frame_object.h"

// Global variable.
extern struct_frame_object global_frame_object;

// Methods.
void engine_frame_manager_init();
void engine_frame_manager_load();
void engine_frame_manager_update();
void engine_frame_manager_draw();

#endif//_FRAME_MANAGER_H_`