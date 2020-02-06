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
	screen_type_pass = 9,
	screen_type_dead = 10,
	screen_type_cont = 11,
	screen_type_over = 12,
	screen_type_beat = 13,
	screen_type_test = 14,
	screen_type_func = 15,

} enum_screen_type;

//typedef enum tag_enum_direction_type
//{
//	direction_type_none = 0,
//	direction_type_upxx = 1,
//	direction_type_down = 2,
//	direction_type_left = 3,
//	direction_type_rght = 4,
//
//} enum_direction_type;

typedef enum tag_enum_direction_type
{
	direction_type_none = 0x00,
	direction_type_upxx = 0x01,
	direction_type_down = 0x02,
	direction_type_left = 0x04,
	direction_type_rght = 0x08,

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
	tile_type_oneup = 7,
	tile_type_cross = 8,

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

typedef enum tag_enum_actor_type
{
	actor_type_pro = 0,
	actor_type_adi = 1,
	actor_type_suz = 2,
	actor_type_kid = 3,

} enum_actor_type;

typedef enum tag_enum_command_type
{
	command_type_all_empty = 0,

	command_type_gamer_mover = 1,
	command_type_enemy_mover = 2,
	command_type_gamer_speed = 3,
	command_type_enemy_speed = 4,

	//command_type_kid_mover = 1,
	//command_type_pro_mover = 2,
	//command_type_adi_mover = 3,
	//command_type_suz_mover = 4,

	//command_type_kid_speed = 5,
	//command_type_pro_speed = 6,
	//command_type_adi_speed = 7,
	//command_type_suz_speed = 8,

	command_type_end_gamer = MAX_CMD_TYPE - 1,

} enum_command_type;

typedef enum tag_enum_cross_type
{
	cross_type_open = 0,
	cross_type_full = 1,

} enum_cross_type;

typedef enum tag_enum_frame_type
{
	frame_type_stance = 0,
	frame_type_toggle = 1,

} enum_frame_type;

typedef enum tag_enum_offset_type
{
	offset_type_none = 0,
	offset_type_one = 1,
	offset_type_two = 2,

} enum_offset_type;

#endif//_ENUM_MANAGER_H_