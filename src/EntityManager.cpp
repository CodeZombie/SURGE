#include "EntityManager.h"

Engine::EntityManager::EntityManager() {
	logMessage("EntityManager Created");
	for (int i = 0; i < MAX_ENTITIES; i++) {
		entity[i] = NULL;
	}
}

Engine::EntityManager::~EntityManager() {
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if (entity[i] != NULL) {
			delete(entity[i]);
		}
	}
	logMessage("Entity Manager Deleted");
}
Engine::Entity* Engine::EntityManager::createEntity(Engine::Entity *entity_, Sprite *sprite_, int x, int y) {
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if (!entity[i]) {
			entity[i] = entity_;//new Entity();
			entity[i]->setSprite(sprite_);
			entity[i]->setX(x);
			entity[i]->setY(y);
			//logMessage("Entity Created.");
			return entity[i];
		}
	}
	logMessage("ERROR: Entity failed to be created: too many entities.");
	return NULL;
}

void Engine::EntityManager::draw(Camera *camera_) {
	
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if (entity[i]) {
			
			entity[i]->draw(camera_);
		}
	}

}

void Engine::EntityManager::dispatchMessage(enum Message message_) {
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if (entity[i]) {
			entity[i]->dispatchMessage(message_);
		}
	}
}

void Engine::EntityManager::update(float dt) {
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if (entity[i]) {
			
			entity[i]->update(dt);
		}
	}
}


