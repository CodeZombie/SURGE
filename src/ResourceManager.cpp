#include "ResourceManager.h"

Engine::Sprite *Engine::ResourceManager::sprite[128];
//SoundObject *sound[128];

void Engine::ResourceManager::initialize() {
	logMessage("Resource Manager Initialized");
	for (int i = 0; i < 128;i++) {
		sprite[i] = NULL;
	}
}

void Engine::ResourceManager::deinitialize() {
	for (int i = 0;i < 128; i++) {
		if (sprite[i] != NULL) {
			delete(sprite[i]);
		}
	}
	logMessage("Resource Manager deinitialized");
}

Engine::Sprite *Engine::ResourceManager::loadSprite(std::string name_, int frames_) {
	printf(" * Trying to load '%s'... ", name_.c_str());
	/* check if resource is already loaded... and return it if it is !!!!! */

	SDL_Surface *tempSurface;
	SDL_Texture *texture;

	tempSurface = SDL_LoadBMP(name_.c_str());

	if (tempSurface == 0) {//image didn't load
		logMessage("Sprite could not load. ERROR 1");
		return 0;
	}

	texture = SDL_CreateTextureFromSurface(Engine::Graphics::getRenderer(), tempSurface);
	SDL_FreeSurface(tempSurface);

	if (texture == 0) { //copy function failed
		logMessage("sprite could not load ERROR 2");
		return 0;
	}

	for (int i = 0;i < 64; i++) {
		if (sprite[i] == NULL) {
			sprite[i] = new Sprite(texture, name_, frames_);
			logMessage("sprite succesfully created");
			return sprite[i];
		}
	}

	return NULL;
}

Engine::Sprite *Engine::ResourceManager::getSprite(std::string name_) {
	for (int i = 0;i < 128; i++) {
		if (sprite[i] != NULL) {
			if (std::strcmp(sprite[i]->getName().c_str(), name_.c_str()) == 0) {
				return sprite[i];
			}
		}
	}
	logMessage(" ! ERROR: Could not find sprite in memory.");
	//return loadSprite(name_);
	return NULL;
}