#ifndef _ENUM_MANAGER_H_
#define _ENUM_MANAGER_H_

#include "global_manager.h"

typedef enum tag_enum_screen_type
{
	screen_type_none = 0,
	screen_type_splash = 1,
	screen_type_title = 2,
	screen_type_intro = 3,
	screen_type_load = 4,
	screen_type_demo = 5,
	screen_type_play = 6,
	screen_type_record = 7,
	screen_type_save = 8,
	screen_type_test = 9,
	screen_type_func = 10,
	screen_type_beat = 11,

} enum_screen_type;

typedef enum tag_enum_direction_type
{
	direction_type_none = 0,
	direction_type_upxx = 1,
	direction_type_down = 2,
	direction_type_left = 3,
	direction_type_rght = 4,

} enum_direction_type;

typedef enum tag_enum_lifecycle_type
{
	lifecycle_type_idle = 0,
	lifecycle_type_move = 1,
	lifecycle_type_dead = 2,

} enum_lifecycle_type;

typedef enum tag_enum_tile_type
{
	tile_type_blank = 0,
	tile_type_trees = 1,
	tile_type_candy = 2,
	tile_type_bonusA = 3,
	tile_type_bonusB = 4,
	tile_type_bonusC = 5,
	tile_type_bonusD = 6,

} enum_tile_type;

typedef enum tag_enum_coll_type
{
	coll_type_empty = 0,
	coll_type_block = 1,

} enum_coll_type;

typedef enum tag_enum_exit_type
{
	exit_type_public = 0,
	exit_type_closed = 1,

} enum_exit_type;

typedef enum tag_enum_tree_type
{
	tree_type_avoid = 0,
	tree_type_death = 1,

} enum_tree_type;

typedef enum tag_enum_mama_type
{
	mama_type_pro = 0,
	mama_type_adi = 1,
	mama_type_suz = 2,

} enum_mama_type;

typedef enum tag_enum_command_type
{
	command_type_empty = 0,
	command_type_fire = 1,
	command_type_jump = 2,
	command_type_move = 3,
	command_type_bank4 = 4,
	command_type_bank5 = 5,
	command_type_bank6 = 6,
	command_type_bank7 = 7,
	command_type_speed = 8,

	command_type_session = MAX_CMD_TYPE - 1,

} enum_command_type;

typedef enum tag_enum_cross_type
{
	cross_type_open = 0,
	cross_type_full = 1,

} enum_cross_type;

#endif//_ENUM_MANAGER_H_