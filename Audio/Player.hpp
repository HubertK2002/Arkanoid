#pragma once
#include <SDL_mixer.h>
#include <SDL.h>
#include <stdio.h>

class Player
{
public:
	Player();
	void playMainMusicTheme() { Mix_PlayMusic(mainMusic, -1); }
	void ballWallBounceSoundEffect() { Mix_PlayChannel(-1, ballWallBounce, 0); }
	void ballBrickBounceSoundEffect() { Mix_PlayChannel(-1, brickBounce, 0); }
private:
	//music
	Mix_Music* mainMusic;
	//soundEffects
	Mix_Chunk* ballWallBounce;
	Mix_Chunk* brickBounce;
};