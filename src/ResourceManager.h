#pragma once
#include <fstream>
#include <iostream>
#include "Logger.h"
#include "Sprite.h"
#include "Graphics.h"
namespace Engine{
	namespace ResourceManager {
		extern Sprite *sprite[128];
		//extern SoundObject *sound[128];

		extern void initialize();
		extern void deinitialize();

		extern Sprite *loadSprite(std::string name_, int frames_);
		extern Sprite *getSprite(std::string name_);
	}
}