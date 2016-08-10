#include <iostream>
#include "Engine.h"
#include "Logger.h"
#include "Graphics.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include <time.h>
#include "InputManager.h"

#undef main

/*
         SURGE:
SDL Ultra-Rad Game Engine

TODO:
	INTERFACE (UI):
		interface objects will be classes. They will be managed by an interfaceManager held by each Scene.
		each interface object can be something simple like a button or as complex as a floating menu.
		They will have properties like invisible, clickable, etc. 
		Each interface will have an array with ~16 ptrs to other interfaces. These child-interfaces will stick to the x/y pos
		of the parent interface. This format will be used to develop things like floating menus or buttons with text.
		Menu positioning must always be in percentage and/or distance-from-window-edge

	Graphics will hold stuff about the screen, then the scene will hold the camera, and everything but UI elements will need the camera to be drawn,
		so they will be tight-coupled to it via arguemnt passes to draw.
		so like, map->draw(camera); will call a bunch of graphics->drawSpriteInCamera(camera, sprite, x,y); calls
*/

int main(void) {
	Engine::logMessage("Starting engine...");
	Engine::Graphics::initialize(1280, 720, 1280, 720);

	Engine::ResourceManager::initialize();
		//load all resources here...
		Engine::ResourceManager::loadSprite("BANE.bmp", 1);
		Engine::ResourceManager::loadSprite("CIA.bmp", 1);
		Engine::ResourceManager::loadSprite("tiles.bmp", 4);

	Engine::SceneManager::initialize(new TestScene());

	Engine::logMessage("\n RUNNING... \n");
	
	/*	Delta Time Logic:
		get Delta time in Milliseconds.
		if 1/60ths of a second have passed (16ms) since the last logicframe:
			update the game logic with a delta time of 1 (for the 1 missed logicframe)
			subtract 16 from the delta time
			repeat until delta time is less than 16
		update game logic with a delta time with a reference time of 16ms for each frame.
	
	*/
	float lFramesPerSecond = 60;
	float lFrameDuration = (1 / lFramesPerSecond) * 1000;
	float deltaTime = 0;
	float lastDeltaTime = SDL_GetTicks();

	//for calculating framerate:
	int frameCount = 0;
	int fpsLastTime = 0;

	while (Engine::running) {
		deltaTime = SDL_GetTicks() - lastDeltaTime;//get time in MS since last frame
		lastDeltaTime = SDL_GetTicks();
		
		Engine::InputManager::update();//update inputmanager

		while (deltaTime > lFrameDuration) { //if 1/60ms has passed
			Engine::SceneManager::update(1);
			deltaTime -= lFrameDuration;
		}
		if(deltaTime > 0) { //if there is more than 0, but less than 1 frames worth of deltatime left:
			Engine::SceneManager::update((deltaTime/1000) * lFramesPerSecond);
		}

		Engine::SceneManager::draw(); //drawing happens independantly of game logic
		Engine::Graphics::flipBuffer();

		/*calculate FPS*/
		if (fpsLastTime + 1000 < lastDeltaTime) {
			std::cout << "FRAMERATE: " << frameCount << std::endl;
			fpsLastTime = lastDeltaTime;
			frameCount = 0;
		}
		frameCount++;
	}

	//maybe show some closer scene thing here
	Engine::SceneManager::deinitialize();
	Engine::Graphics::deinitialize();
	Engine::ResourceManager::deinitialize();
	SDL_Quit();
	system("PAUSE");
	return 0;
}