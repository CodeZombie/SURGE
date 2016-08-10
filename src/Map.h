#pragma once
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "SDL.h"
#include "Graphics.h"
#include "ResourceManager.h"
#include "Camera.h"
//the "MapManager" only manages the tiles in the map. It does not handle entities or any game logic.
namespace Engine {
	class Map {
	private:
		int tiles[64][64];
		Sprite *sprite;
	public:
		Map(Sprite *sprite_);
		~Map();
		void loadMap(); //string pathname
		void checkCollision(int x_, int y_, int w_, int h_); //either an entity pointer or x,y,w,h
		void draw(Camera *camera_, int x_, int y_, int w_, int h_); //give it either a camera pointer, or bounding box
	};
}