#pragma once
#include "SDL.h"
#include "Logger.h"
#include "Sprite.h"
#include "Camera.h"
namespace Engine {

	namespace Graphics {
		struct RenderLayer {
			bool active = false;
			int index = 0;
			SDL_Texture *texture;
			struct RenderLayer *next = NULL;
		};

		extern struct RenderLayer zeroLayer;

		//viewport is the actual rectangle of display in the game window.
		extern int viewportWidth;
		extern int viewportHeight;

		extern int virtualViewportWidth;
		extern int virtualViewportHeight;

		extern SDL_Window *window;
		extern SDL_Renderer *renderer;

		extern SDL_Texture *zLayer[64];

		extern void initialize(int viewportWidth_, int viewportHeight_, int virtualViewportWidth_, int virtualViewportHeight_);
		extern void deinitialize();

		extern struct RenderLayer *getRenderLayer(int zIndex_);

		extern SDL_Renderer *getRenderer();
		//rename to "drawSprite" (also add functionality so if camera_ == null, the sprite is just drawn  above any camera)
		extern void draw(Camera * camera_, Sprite *sprite_, int x_, int y_, int width_, int height_, int frame_, int zIndex_);
		extern void flipBuffer();
	}
}