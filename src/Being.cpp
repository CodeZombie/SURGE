#include "Being.h"
#include "Scene.h"

Being::Being(Engine::Scene *scene_) : Engine::Entity(scene_){
	setAlarm(0, 60);
	maxVelocity = 10;
	xVelocity = 0;
	yVelocity = 0;
}

Being::~Being() {
}

void Being::update(float dt) {
	Entity::update(dt); //call super method
	
	if (Engine::InputManager::isKeyDown(SDLK_w)) {
		if (yVelocity > -maxVelocity) {
			yVelocity -= dt;
		}
	}
	else if (Engine::InputManager::isKeyDown(SDLK_s)) {
		if (yVelocity < maxVelocity) {
			yVelocity += dt;
		}
	}
	else {
		if (yVelocity != 0) {
			yVelocity += (yVelocity > 0) ? -dt : dt;
			if (yVelocity <= 1 && yVelocity >= -1) {
				yVelocity = 0;
			}
		}
	}
	
	if (Engine::InputManager::isKeyDown(SDLK_a)) {
		if (xVelocity > -maxVelocity) {
			xVelocity -= dt;
		}
	}
	else if (Engine::InputManager::isKeyDown(SDLK_d)) {
		if (xVelocity < maxVelocity) {
			xVelocity += dt;
		}
	}
	else {
		if (xVelocity != 0) {
			xVelocity += (xVelocity > 0) ? -dt : dt;
			if (xVelocity < 1 && xVelocity > -1) {
				xVelocity = 0;
			}
		}

	}
	x += xVelocity*dt;
	y += yVelocity*dt;

	scene->getCamera()->centerOnPoint(x, y);
}

void Being::alarm(int alarmID_) {
	if (alarmID_ == 0) {
		Engine::PersistentData::setPersistentInteger(PINT_PLAYER_HEALTH, Engine::PersistentData::getPersistentInteger(PINT_PLAYER_HEALTH) - 1);
		std::cout << Engine::PersistentData::getPersistentInteger(PINT_PLAYER_HEALTH) << std::endl;
		setAlarm(0, 60);
	}
}

void Being::draw(Engine::Camera *camera_) {
	if (sprite) {
		Engine::Graphics::draw(camera_, sprite, x, y, w, h, 0, 22);
	}
}