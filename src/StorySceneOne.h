#pragma once
#include "Scene.h"

class StorySceneOne : public Engine::Scene {
public:
	StorySceneOne();
	~StorySceneOne();
	virtual void update(float dt);
	virtual void draw();
};

