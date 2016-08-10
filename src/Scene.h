#pragma once
#include "SceneID.h"
#include "Logger.h"
#include "EntityManager.h"
#include "Map.h"
#include "Graphics.h"
#include "Camera.h"
#include "UIElement.h"

namespace Engine {
	class Scene {
	protected:
		Scene *previousScene;
		EntityManager *entityManager;
		Map *map;
		Camera *camera;
		int sceneToGoto;
		enum SceneID sceneToChangeTo;
		//resource manager
		//	SCENE MANAGER SHOULD HOLD INTER-SCENE SHARED RESOURCES LIKE LOADING SCREEN STUFF
		//EntityManager
		//Map
	public:
		Scene();
		virtual ~Scene();
		void dispatchMessage(enum Message message_);
		virtual void update(float dt);
		virtual void draw();
		void changeScene(enum SceneID sceneID_);
		enum SceneID checkSceneChange();
		Camera *getCamera();
	};
}