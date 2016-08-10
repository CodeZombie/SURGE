#pragma once
#include "SDL.h"
#include "Engine.h"

//https://wiki.libsdl.org/SDL_Keycode

namespace Engine {
	namespace InputManager {
		extern void initialize();
		extern void deinitialize();
		extern void update();
		extern bool isKeyDown(SDL_Keycode k_);
	}
}