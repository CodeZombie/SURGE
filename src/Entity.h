#pragma once
#include "SceneID.h"
#include "Sprite.h"
#include "Graphics.h"
#include "EngineState.h"
#include "InputManager.h"
#include "PersistentData.h"
#include "PersistentDataID.h"
#include "Camera.h"

namespace Engine {
	class Scene;
	class Entity {
	protected:
		const static int numberOfAlarms = 8;
		Sprite *sprite;
		float x, y, w, h;
		float alarmCountdown[numberOfAlarms];
		Scene *scene;
	public:
		Entity(Scene *scene_);
		~Entity();

		/* EVENTS */
		virtual void draw(Camera *camera_);
		virtual void collision(Entity *other_);
		//void interact(Entity *other_, enum Interact_Type);
		virtual void update(float dt);

		virtual void mouseEvent();
		virtual void alarm(int alarmID_);
		virtual void dispatchMessage(enum Message message_);

		/* SETTERS */
		void setSprite(Sprite *sprite_);
		void setAlarm(int alarmID_, int time_);
		void setX(int x_);
		void setY(int y_);
		void setW(int w_);
		void setH(int h_);

		/* GETTERS */
		Sprite *getSprite();
		int getX();
		int getY();
		int getW();
		int getH();
	};
}