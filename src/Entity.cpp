#include "Entity.h"

Engine::Entity::Entity(Scene *scene_) {
	sprite = NULL;
	x = 0;
	y = 0; 
	w = 32;
	h = 32;
	for (int i = 0; i < numberOfAlarms; i++) {
		alarmCountdown[i] = -1; //-1 means the alarm is deactivated
	}
	scene = scene_;
}

Engine::Entity::~Entity() {
	logMessage("entity deleted");
}

/* #####################################  */
/*              EVENTS                    */
/* #####################################  */

void Engine::Entity::draw(Camera *camera_) {
	if (sprite) {
		Engine::Graphics::draw(camera_, sprite, x, y, w, h, 0, 1);
	}
}

void Engine::Entity::update(float dt) {
	//alarm logic:
	//	For each alarm that is not -1, count down.
	//	If the alarm reaches -1, trigger the event.
	for (int i = 0; i < numberOfAlarms; i++) {
		if (alarmCountdown[i] > -1) {
			alarmCountdown[i] -= 1*dt;
			if (alarmCountdown[i] < 0) {
				alarm(i);
			}
		}
	}
}

void Engine::Entity::collision(Entity *other_) {

}

void Engine::Entity::mouseEvent() {

}

void Engine::Entity::alarm(int alarmID_) {

}

void Engine::Entity::dispatchMessage(enum Message message_) {

}

/* #####################################  */
/*             SETTERS                    */
/* #####################################  */

void Engine::Entity::setSprite(Sprite *sprite_) {
	sprite = sprite_;
}

void Engine::Entity::setAlarm(int alarmID_, int time_) {
	if (alarmID_ > numberOfAlarms - 1) {
		logMessage("ERROR: Alarm ID out of range");
	}else {
		alarmCountdown[alarmID_] = time_;
	}
}

void Engine::Entity::setX(int x_) {
	x = x_;
}

void Engine::Entity::setY(int y_) {
	y = y_;
}

void Engine::Entity::setW(int w_) {
	w = w_;
}

void Engine::Entity::setH(int h_) {
	h = h_;
}

/* #####################################  */
/*             GETTERS                    */
/* #####################################  */

Engine::Sprite *Engine::Entity::getSprite() {
	return sprite;
}

int Engine::Entity::getX() {
	return x;
}

int Engine::Entity::getY() {
	return y;
}

int Engine::Entity::getW() {
	return w;
}

int Engine::Entity::getH() {
	return h;
}