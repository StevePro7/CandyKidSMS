#include "audio_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\devkit\_snd_manager.h"
#include "..\object\audio_object.h"

// IMPORTANT disable compiler warning 196
#ifdef _CONSOLE
#else
#pragma disable_warning 196
#endif

// Private helper functions.
static void play_music( unsigned char *music, unsigned char bank );
static void play_music_norepeat( unsigned char *music, unsigned char bank );
static void play_sound( unsigned char *sound );

void engine_audio_manager_music_game( unsigned char index )
{
	play_music( ( unsigned char* ) game_audio_data[ index ], game_audio_bank[ index ] );
}
void engine_audio_manager_music_title()
{
	play_music_norepeat( ( unsigned char* ) title_audio_data[ 0 ], title_audio_bank[ 0 ] );
}
void engine_audio_manager_music_over()
{
	play_music_norepeat( ( unsigned char* ) over_audio_data[ 0 ], over_audio_bank[ 0 ] );
}
void engine_audio_manager_music_beat()
{
	play_music_norepeat( ( unsigned char* ) beat_audio_data[ 0 ], beat_audio_bank[ 0 ] );
}

static void play_music( unsigned char *music, unsigned char bank )
{
	//struct_hack_object *ho = &global_hack_object;
	//if( !ho->hack_music )
	//{
	//	return;
	//]}

	devkit_SMS_mapROMBank( bank );
	devkit_PSGPlay( music );
}
static void play_music_norepeat( unsigned char *music, unsigned char bank )
{
	//struct_hack_object *ho = &global_hack_object;
	//if( !ho->hack_music )
	//{
	//	return;
	//}

	devkit_SMS_mapROMBank( bank );
	devkit_PSGPlayNoRepeat( music );
}
static void play_sound( unsigned char *sound )
{
	//struct_hack_object *ho = &global_hack_object;
	//if( !ho->hack_sound )
	//{
	//	return;
	//}

	devkit_PSGSFXPlay( sound, devkit_SFX_CHANNEL2() );
}