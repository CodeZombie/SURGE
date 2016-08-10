#include "Engine.h"
bool Engine::running = true;

void Engine::stop() {
	running = false;
}