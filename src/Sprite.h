#pragma once
#include <string>
#include "SDL.h"
#include "Logger.h"
namespace Engine {
	class Sprite {
	private:
		int frames, frameWidth, frameHeight;
		std::string name;//perhaps make these enums
		SDL_Texture *texture;
	public:
		Sprite(SDL_Texture *texture_, std::string name_, int frames_);
		~Sprite();
		std::string getName();
		int getNumberOfFrames();
		int getFrameWidth();
		int getFrameHeight();
		SDL_Texture *getTexture();
	};
}