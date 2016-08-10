#include "SceneManager.h"

Engine::Scene *Engine::SceneManager::currentScene;

void Engine::SceneManager::initialize(Scene *scene_) {
	currentScene = scene_;
}

void Engine::SceneManager::deinitialize() {
	delete(currentScene);
	logMessage("Scene Manager deinitialized");
}

void Engine::SceneManager::replaceCurrentScene(Scene *scene_) {
	delete(currentScene);
	currentScene = scene_;
}

void Engine::SceneManager::update(float dt) {
	//transition shit will need to be handled here
	enum SceneID sceneToChangeTo = currentScene->checkSceneChange();
	if (sceneToChangeTo == MAIN_MENU) {
		logMessage("SHOULD CHANGE TO MAIN MENU");
	}
	else if (sceneToChangeTo == SCENE_STORY_ONE) {
		logMessage("SHOULD CHANGE TO SCENE_STORY_ONE");
		replaceCurrentScene(new StorySceneOne());
	}
	else if (sceneToChangeTo == SCENE_STORY_TWO) {
		logMessage("SHOULD CHANGE TO SCENE_STORY_TWO");
	}
	currentScene->update(dt);
}

void Engine::SceneManager::draw() {
	currentScene->draw();
}