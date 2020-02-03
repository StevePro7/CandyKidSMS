#include "audio_object.h"

#include "..\banks\bank6.h"
#include "..\banks\bank7.h"

// Game.
const unsigned char *game_audio_data[] = 
{
	//music_game01_psg,
	//music_game02_psg,
	music_game03_psg,
};
const unsigned char game_audio_bank[] =
{
	//music_title_psg_bank,
	//music_game01_psg_bank,
	//music_game02_psg_bank,
	music_game03_psg_bank,
};

// Title.
const unsigned char *title_audio_data[] =
{
	music_title_psg,
};
const unsigned char title_audio_bank[] =
{
	music_title_psg_bank,
};

// Beat.
const unsigned char *beat_audio_data[] = 
{
	music_beat_psg,
};
const unsigned char beat_audio_bank[] =
{
	music_beat_psg_bank,
};

// Over.
const unsigned char *over_audio_data[] =
{
	music_over_psg,
};
const unsigned char over_audio_bank[] =
{
	music_over_psg_bank,
};