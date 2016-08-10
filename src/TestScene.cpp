#include "TestScene.h"

TestScene::TestScene() {
	map = new Engine::Map(Engine::ResourceManager::getSprite("tiles.bmp"));
	Engine::Entity *e = entityManager->createEntity(new Engine::Entity(this), Engine::ResourceManager::getSprite("BANE.bmp"), 32, 32);
	entityManager->createEntity(new Being(this), Engine::ResourceManager::getSprite("CIA.bmp"), 128, 128);
	for (int i = 0; i < 1000; i++) {
		entityManager->createEntity(new Spazz(this), Engine::ResourceManager::getSprite("BANE.bmp"), rand() % 1024, rand() % 1024);
	}
	
	map->loadMap();
	Engine::PersistentData::setPersistentInteger(PINT_PLAYER_HEALTH, 100); //since this is the first scene, set the players health to the default.
	Engine::UIElement *xxx = new Engine::UIElement();
}

TestScene::~TestScene() {
	delete(map);
}

void TestScene::update(float dt) {
	if (Engine::InputManager::isKeyDown(SDLK_k)) {
		changeScene(SCENE_STORY_ONE);
	}
	Scene::update(dt);
}

void TestScene::draw() {
	map->draw(camera, 0, 0, 0, 0);
	Scene::draw();
}