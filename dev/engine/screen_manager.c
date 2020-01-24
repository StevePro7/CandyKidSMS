#include "screen_manager.h"
#include "global_manager.h"
#include "enum_manager.h"

static void( *load_method[ MAX_SCREEENS ] )( );
static void( *update_method[ MAX_SCREEENS ] )( unsigned char *screen_type );

static unsigned char curr_screen_type;
static unsigned char next_screen_type;

void engine_screen_manager_init( unsigned char open_screen_type )
{
	next_screen_type = open_screen_type;
	curr_screen_type = screen_type_none;
}

void engine_screen_manager_update()
{
}