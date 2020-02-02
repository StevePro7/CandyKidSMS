#include "actor_manager.h"
#include "enemy_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "gamer_manager.h"

#define BYTE_NIBBLE_MASK	0x0F

// Public methods.
void engine_actor_manager_update()
{
}

// Execute commands.
void engine_actor_manager_exec_gamer_mover( unsigned char args )
{
	engine_gamer_manager_move( args );
}
void engine_actor_manager_exec_enemy_mover( unsigned char args )
{
	unsigned char enemy;
	unsigned char direction;

	enemy = args & BYTE_NIBBLE_MASK;
	direction = ( args >> 4 ) & BYTE_NIBBLE_MASK;

	engine_enemy_manager_move( enemy, direction );
	//engine_enemy_manager_move( actor_type_pro, args );
}
void engine_actor_manager_exec_gamer_speed( unsigned char args )
{
	args = 0;
}
void engine_actor_manager_exec_enemy_speed( unsigned char args )
{
	args = 0;
}


void engine_actor_manager_exec_kid_mover( unsigned char args )
{
	//engine_font_manager_draw_text( "EXEC FIRE", 2, 12 );
	//engine_font_manager_draw_data( args, 17, 12 );
	//TODO revert
	engine_gamer_manager_move( args );
}
void engine_actor_manager_exec_pro_mover( unsigned char args )
{
	//engine_font_manager_draw_text( "EXEC JUMP", 2, 13 );
	//engine_font_manager_draw_data( args, 17, 13 );

	engine_enemy_manager_move( actor_type_pro, args );
}
void engine_actor_manager_exec_adi_mover( unsigned char args )
{
	engine_font_manager_draw_text( "EXEC MOVE", 2, 14 );
	engine_font_manager_draw_data( args, 17, 14 );
	//engine_gamer_manager_move( args );
}
void engine_actor_manager_exec_suz_mover( unsigned char args )
{
	engine_font_manager_draw_text( "EXEC BANK4", 2, 15 );
	engine_font_manager_draw_data( args, 17, 15 );
}
void engine_actor_manager_exec_kid_speed( unsigned char args )
{
	engine_font_manager_draw_text( "EXEC BANK5", 2, 16 );
	engine_font_manager_draw_data( args, 17, 16 );
}
void engine_actor_manager_exec_pro_speed( unsigned char args )
{
	engine_font_manager_draw_text( "EXEC BANK6", 2, 17 );
	engine_font_manager_draw_data( args, 17, 17 );
}
void engine_actor_manager_exec_adi_speed( unsigned char args )
{
	engine_font_manager_draw_text( "EXEC BANK7", 2, 18 );
	engine_font_manager_draw_data( args, 17, 18 );
}
void engine_actor_manager_exec_suz_speed( unsigned char args )
{
	engine_font_manager_draw_text( "EXEC SPEED", 2, 19 );
	engine_font_manager_draw_data( args, 17, 19 );
}


// Undo commands.
void engine_actor_manager_undo_kid_mover( unsigned char args )
{
	engine_font_manager_draw_text( "                            ", 2, 12 );
	args = 0;
}
void engine_actor_manager_undo_pro_mover( unsigned char args )
{
	engine_font_manager_draw_text( "                            ", 2, 13 );
	args = 0;
}
void engine_actor_manager_undo_adi_mover( unsigned char args )
{
	engine_font_manager_draw_text( "                            ", 2, 14 );
	args = 0;
}
void engine_actor_manager_undo_suz_mover( unsigned char args )
{
	engine_font_manager_draw_text( "                            ", 2, 15 );
	args = 0;
}
void engine_actor_manager_undo_kid_speed( unsigned char args )
{
	engine_font_manager_draw_text( "                            ", 2, 16 );
	args = 0;
}
void engine_actor_manager_undo_pro_speed( unsigned char args )
{
	engine_font_manager_draw_text( "                            ", 2, 17 );
	args = 0;
}
void engine_actor_manager_undo_adi_speed( unsigned char args )
{
	engine_font_manager_draw_text( "                            ", 2, 18 );
	args = 0;
}
void engine_actor_manager_undo_suz_speed( unsigned char args )
{
	engine_font_manager_draw_text( "                            ", 2, 19 );
	args = 0;
}


void engine_actor_manager_undo_gamer_mover( unsigned char args )
{
	args = 0;
}
void engine_actor_manager_undo_enemy_mover( unsigned char args )
{
	args = 0;
}
void engine_actor_manager_undo_gamer_speed( unsigned char args )
{
	args = 0;
}
void engine_actor_manager_undo_enemy_speed( unsigned char args )
{
	args = 0;
}