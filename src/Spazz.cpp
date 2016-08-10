#include "Spazz.h"



Spazz::Spazz(Engine::Scene *scene_) : Engine::Entity(scene_) {
	setAlarm(0, rand() % 100);
	xvel = 0;
	yvel = 0;
}

Spazz::~Spazz() {
}

void Spazz::update(float dt) {
	Entity::update(dt); //call super method
	x += xvel*dt;
	y += yvel*dt;
	if (x < 0 || x > 1024){
		x = 512;
	}
	if (y < 0 || y > 1024) {
		y = 512;
	}

}

void Spazz::alarm(int alarmID_) {
	if (alarmID_ == 0) {

		xvel = -3 + (rand() % (6+1));
		yvel = -3 + (rand() % (6+1));
		setAlarm(0, rand() % 20);
	}
}