#pragma once
#include "Entity.h"
#include "Being.h"
#include "Spazz.h"
#include "ResourceManager.h"
#include "Logger.h"

namespace Engine {
	class EntityManager {
	private:
		static const int MAX_ENTITIES = 100000;
		Engine::Entity *entity[MAX_ENTITIES];
	public:
		EntityManager();
		~EntityManager();
		Engine::Entity* createEntity(Engine::Entity *entity_, Sprite *sprite_, int x, int y);
		void draw(Camera *camera_);

		void dispatchMessage(enum Message message_);

		void update(float dt);
	};
}