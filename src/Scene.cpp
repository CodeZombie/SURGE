#include "Scene.h"

Engine::Scene::Scene() {

	Engine::logMessage("Scene created");
	entityManager = new EntityManager();
	previousScene = NULL;
	camera = new Camera(Engine::Graphics::viewportWidth, Engine::Graphics::viewportHeight);
}

Engine::Scene::~Scene() {
	delete(entityManager);
	logMessage("Scene Deleted");
}

void Engine::Scene::dispatchMessage(enum Message message_) {
	entityManager->dispatchMessage(message_);
}

void Engine::Scene::update(float dt) {
	entityManager->update(dt);	
}

void Engine::Scene::draw() {
	entityManager->draw(camera);
}

void Engine::Scene::changeScene(enum SceneID sceneID_) {
	sceneToChangeTo = sceneID_;
}

enum SceneID Engine::Scene::checkSceneChange() {
	return sceneToChangeTo;
}


Engine::Camera *Engine::Scene::getCamera() {
	return camera;
}