#include "audio_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\devkit\_snd_manager.h"
#include "..\object\audio_object.h"
#include "..\psg.h"

// IMPORTANT disable compiler warning 196
#ifdef _CONSOLE
#else
#pragma disable_warning 196
#endif

#define sound_accept_psg			sound_accept_psg
#define sound_death_psg			sound_death_psg
#define sound_gem_psg				sound_gem_psg
#define sound_level_psg			sound_level_psg
#define sound_power_psg			sound_power_psg
#define sound_reset_psg			sound_reset_psg

// Private helper functions.
static void play_music( unsigned char *music, unsigned char bank );
static void play_music_norepeat( unsigned char *music, unsigned char bank );
static void play_sound( unsigned char *sound );

// Music.
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

// Sound.
void engine_audio_manager_sound_accept()
{
	play_sound( ( unsigned char* ) sound_accept_psg );
}
void engine_audio_manager_sound_death()
{
	play_sound( ( unsigned char* ) sound_death_psg );
}
void engine_audio_manager_sound_gem()
{
	play_sound( ( unsigned char* ) sound_gem_psg );
}
void engine_audio_manager_sound_level()
{
	play_sound( ( unsigned char* ) sound_level_psg );
}
void engine_audio_manager_sound_power()
{
	play_sound( ( unsigned char* ) sound_power_psg );
}
void engine_audio_manager_sound_reset()
{
	play_sound( ( unsigned char* ) sound_reset_psg );
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
	unsigned char status;
	//struct_hack_object *ho = &global_hack_object;
	
	//if( !ho->hack_sound )
	//{
	//	return;
	//}

	// If sound effect already playing then return.
	status = devkit_PSGSFXGetStatus();
	if( status )
	{
		return;
	}

	devkit_PSGSFXPlay( sound, devkit_SFX_CHANNEL2() );
}