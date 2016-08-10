#include "InputManager.h"

void Engine::InputManager::initialize() {

}

void Engine::InputManager::deinitialize() {

}

void Engine::InputManager::update() {
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
			//SceneManager::keyEvent(e.key.keysym.sym, e.type); //THIS REQUIRES WEIRD CIRCULAR REFERENCING, WHICH WE WANT TO AVOID.
																//PROBABLY DONT DO THIS. >:^(
		}
		else if (e.type == SDL_QUIT) {
			Engine::stop();
		}
	}
}

bool Engine::InputManager::isKeyDown(SDL_Keycode k_) {
	SDL_PumpEvents();
	const Uint8 * keystate = SDL_GetKeyboardState(NULL);
	if (keystate[SDL_GetScancodeFromKey(k_)]) {
		return true;
	}
	return false;
}