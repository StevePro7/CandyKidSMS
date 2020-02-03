#ifndef _AUDIO_MANAGER_H_
#define _AUDIO_MANAGER_H_

// Music.
void engine_audio_manager_music_game( unsigned char index );
void engine_audio_manager_music_title();
void engine_audio_manager_music_over();
void engine_audio_manager_music_beat();

// Sound.
void engine_audio_manager_sound_accept();
void engine_audio_manager_sound_death();
void engine_audio_manager_sound_gem();
void engine_audio_manager_sound_level();
void engine_audio_manager_sound_power();
void engine_audio_manager_sound_reset();

#endif//_AUDIO_MANAGER_H_