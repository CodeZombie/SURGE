#include "Map.h"

Engine::Map::Map(Sprite *sprite_) {
	sprite = sprite_;
}


Engine::Map::~Map(){

}

void Engine::Map::loadMap() {
	//fill up the tiles[][] with test data until i can implement a proper external map data system.
	for (int x = 0; x < 32; x++) {
		for (int y = 0; y < 32; y++) {
			tiles[x][y] = int(rand()  % (2 + 1));
		}
	}
}

void Engine::Map::checkCollision(int x_, int y_, int w_, int h_) { //rename this function to be more descriptive
	//check if there is a collision between the given bounding box, and a 'solid' tile
	//there should be some clever way of not having to cycle through the entire 2d array, and using maths, simply check against ~4 possible tiles
}

void Engine::Map::draw(Camera *camera_, int x_, int y_, int w_, int h_) {
	int w = sprite->getFrameWidth();
	int h = sprite->getFrameHeight();
	for (int x = 0; x < 32; x++) {
		for (int y = 0; y < 32; y++) {
			Engine::Graphics::draw(camera_, sprite, x*w, y*h, w, h, tiles[x][y], 0);
		}
	}
	//the bounding box here is the viewport (camera)
	//only draws tiles that fall within the BB, relative to it's position.
}