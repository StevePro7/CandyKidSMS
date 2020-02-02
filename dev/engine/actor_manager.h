#ifndef _ACTOR_MANAGER_H_
#define _ACTOR_MANAGER_H_

// Public method.
void engine_actor_manager_update();

// Execute commands.
void engine_actor_manager_exec_gamer_mover( unsigned char args );
void engine_actor_manager_exec_enemy_mover( unsigned char args );
void engine_actor_manager_exec_gamer_speed( unsigned char args );
void engine_actor_manager_exec_enemy_speed( unsigned char args );

void engine_actor_manager_exec_kid_mover( unsigned char args );
void engine_actor_manager_exec_pro_mover( unsigned char args );
void engine_actor_manager_exec_adi_mover( unsigned char args );
void engine_actor_manager_exec_suz_mover( unsigned char args );
void engine_actor_manager_exec_kid_speed( unsigned char args );
void engine_actor_manager_exec_pro_speed( unsigned char args );
void engine_actor_manager_exec_adi_speed( unsigned char args );
void engine_actor_manager_exec_suz_speed( unsigned char args );

// Undo commands.
void engine_actor_manager_undo_kid_mover( unsigned char args );
void engine_actor_manager_undo_pro_mover( unsigned char args );
void engine_actor_manager_undo_adi_mover( unsigned char args );
void engine_actor_manager_undo_suz_mover( unsigned char args );
void engine_actor_manager_undo_kid_speed( unsigned char args );
void engine_actor_manager_undo_pro_speed( unsigned char args );
void engine_actor_manager_undo_adi_speed( unsigned char args );
void engine_actor_manager_undo_suz_speed( unsigned char args );

void engine_actor_manager_undo_gamer_mover( unsigned char args );
void engine_actor_manager_undo_enemy_mover( unsigned char args );
void engine_actor_manager_undo_gamer_speed( unsigned char args );
void engine_actor_manager_undo_enemy_speed( unsigned char args );

#endif//_ACTOR_MANAGER_H_