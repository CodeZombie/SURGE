#pragma once

#include "Engine.h"
#include "Entity.h"
#include "Logger.h"

class Being: public Engine::Entity {
private:
	float xVelocity, yVelocity, maxVelocity;
public:
	Being(Engine::Scene *scene_);
	~Being();

	virtual void update(float dt);
	virtual void alarm(int alarmID_);
	virtual void draw(Engine::Camera *camera_);
};

