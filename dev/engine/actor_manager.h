#ifndef _ACTOR_MANAGER_H_
#define _ACTOR_MANAGER_H_

// Public method.
void engine_actor_manager_update();

// Execute commands.
void engine_actor_manager_exec_fire( unsigned int args );
void engine_actor_manager_exec_jump( unsigned int args );
void engine_actor_manager_exec_move( unsigned int args );
void engine_actor_manager_exec_bank4( unsigned int args );
void engine_actor_manager_exec_bank5( unsigned int args );
void engine_actor_manager_exec_bank6( unsigned int args );
void engine_actor_manager_exec_bank7( unsigned int args );
void engine_actor_manager_exec_speed( unsigned int args );

// Undo commands.
void engine_actor_manager_undo_fire( unsigned int args );
void engine_actor_manager_undo_jump( unsigned int args );
void engine_actor_manager_undo_move( unsigned int args );
void engine_actor_manager_undo_bank4( unsigned int args );
void engine_actor_manager_undo_bank5( unsigned int args );
void engine_actor_manager_undo_bank6( unsigned int args );
void engine_actor_manager_undo_bank7( unsigned int args );
void engine_actor_manager_undo_speed( unsigned int args );

#endif//_ACTOR_MANAGER_H_