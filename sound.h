#ifndef SOUND_H
#define SOUND_H

enum SoundEffects {
	SFX_NONE,
	SFX_START,
	SFX_BUZZ,
	SFX_CLICK,
	SFX_GETITEM,
	SFX_ITEMREADY,

	SFX_MAX
};

class Sound {
public:
	Sound();
	~Sound();
	void loadAll();
	int playOnce(SoundEffects sfx);
};

extern Sound sound;

#endif
