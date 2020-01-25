#include "hack_manager.h"
#include "global_manager.h"
#include "enum_manager.h"

#define PEEK( addr)			(* ( unsigned char *)( addr ) )
#define POKE( addr, data )	(* ( unsigned char *)( addr ) = ( data ) )

#define HACKER_START		0x0050

// Global variable.
struct_hack_object global_hack_object;

void engine_hack_manager_init()
{
	struct_hack_object *ho = &global_hack_object;

	ho->hack_world = 0;
	ho->hack_round = 0;
	ho->hack_music = 0;
	ho->hack_sound = 0;

#ifndef _CONSOLE

	ho->hack_world = PEEK( HACKER_START + 0 );			// 0x0050		// Set start world no to zero-based value.
	ho->hack_round = PEEK( HACKER_START + 1 );			// 0x0051		// Set start round no to zero-based value.
	ho->hack_music = PEEK( HACKER_START + 2 );			// 0x0052		// Set 0=music to play otherwise disabled.
	ho->hack_sound = PEEK( HACKER_START + 3 );			// 0x0053		// Set 0=sound to play otherwise disabled.

#endif

}


void engine_hack_manager_invert()
{
	struct_hack_object *ho = &global_hack_object;

	// World.
	if( 0 != ho->hack_world )
	{
		if( ho->hack_world > MAX_WORLDS )
		{
			ho->hack_world = MAX_WORLDS;
		}

		// Zero-based index.
		ho->hack_world -= 1;
	}

	// Round.
	if( 0 != ho->hack_round )
	{
		if( ho->hack_round > MAX_ROUNDS )
		{
			ho->hack_round = MAX_ROUNDS;
		}

		// Zero-based index.
		ho->hack_round -= 1;
	}

	// Invert default values.
	ho->hack_music = !ho->hack_music;
	ho->hack_sound = !ho->hack_sound;


	ho->hack_world = 7-1;
	ho->hack_round = 9-1;
}