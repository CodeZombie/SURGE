#include "Sprite.h"

Engine::Sprite::Sprite(SDL_Texture *texture_, std::string name_, int frames_) {
	texture = texture_;
	name = name_;
	frames = frames_;
	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	frameHeight = h;
	frameWidth = w / frames_;
}

Engine::Sprite::~Sprite() {
	SDL_DestroyTexture(texture);
	logMessage("Sprite Deleted");
}

std::string Engine::Sprite::getName() {
	return name;
}

int Engine::Sprite::getNumberOfFrames() {
	return frames;
}

int Engine::Sprite::getFrameWidth() {
	return frameWidth;
}

int Engine::Sprite::getFrameHeight() {
	return frameHeight;
}

SDL_Texture *Engine::Sprite::getTexture() {
	return texture;
}