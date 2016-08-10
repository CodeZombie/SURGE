#pragma once
#include "Entity.h"
class Spazz : public Engine::Entity {
private:
	int xvel, yvel;
public:
	Spazz(Engine::Scene *scene_);
	~Spazz();

	virtual void update(float dt);
	virtual void alarm(int alarmID_);
};

