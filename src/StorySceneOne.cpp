#include "StorySceneOne.h"

StorySceneOne::StorySceneOne(){
	map = new Engine::Map(Engine::ResourceManager::getSprite("tiles.bmp"));
	entityManager->createEntity(new Engine::Entity(this), Engine::ResourceManager::getSprite("BANE.bmp"), 128, 256);
	entityManager->createEntity(new Engine::Entity(this), Engine::ResourceManager::getSprite("BANE.bmp"), 256, 256);
	entityManager->createEntity(new Engine::Entity(this), Engine::ResourceManager::getSprite("BANE.bmp"), 256, 512);
	entityManager->createEntity(new Being(this), Engine::ResourceManager::getSprite("CIA.bmp"), 128, 128);
	map->loadMap();
}

StorySceneOne::~StorySceneOne() {
	delete(map);
}

void StorySceneOne::update(float dt) {
	Scene::update(dt);
}

void StorySceneOne::draw() {
	map->draw(camera, 0, 0, 0, 0);
	Scene::draw();
}