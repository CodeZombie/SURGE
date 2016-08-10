#pragma once
#include "SceneID.h"
#include "InputManager.h"
#include "Scene.h"
#include "TestScene.h"
#include "StorySceneOne.h"
//The main menu scene is loaded, with a previousScene of NULL
//on top of this scene gamescenes are loaded
//when popScene is called, the "previousScene" stored in "currentScene" is set to CurrentScene
//when pushScene is called, a new scene is created with a previousScene of the current scene, and that initial scene is set to current
//when ReplaceCurrentScene is called, the currentScene is directly replaced with a new one (useful when we dont want to keep the previousScene
//	like level switching.
namespace Engine {
	namespace SceneManager {
		extern Scene *currentScene;

		extern void initialize(Scene *scene_);

		extern void deinitialize();

		extern void replaceCurrentScene(Scene *scene_);

		extern void update(float dt);

		extern void draw();

	}
}