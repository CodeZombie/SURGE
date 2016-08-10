#pragma once
#include "Scene.h"

class TestScene : public Engine::Scene {
private:

public:
	TestScene();
	~TestScene();
	virtual void update(float dt);
	virtual void draw();
};