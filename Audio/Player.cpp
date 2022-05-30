#include "Player.hpp"

Player::Player()
{
	SDL_Init(SDL_INIT_AUDIO);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	Mix_AllocateChannels(4);
	mainMusic = Mix_LoadMUS("Audio/Music/awesomeness.wav");
	ballWallBounce = Mix_LoadWAV("Audio/SoundEffect/8bit_bomb_explosion.wav");
	brickBounce = Mix_LoadWAV("Audio/SoundEffect/boom1.wav");
}
