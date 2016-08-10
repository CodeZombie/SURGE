#include "Graphics.h"

SDL_Window *Engine::Graphics::window;
SDL_Renderer *Engine::Graphics::renderer;

struct Engine::Graphics::RenderLayer Engine::Graphics::zeroLayer;

int Engine::Graphics::viewportWidth = 1280;
int Engine::Graphics::viewportHeight = 720;
int Engine::Graphics::virtualViewportWidth = 1280;
int Engine::Graphics::virtualViewportHeight = 720;

void Engine::Graphics::initialize(int viewportWidth_, int viewportHeight_, int virtualViewportWidth_, int virtualViewportHeight_) {

	viewportWidth = viewportWidth_;
	viewportHeight = viewportHeight_;
	virtualViewportWidth = virtualViewportWidth_;
	virtualViewportHeight = virtualViewportHeight_;

	window = SDL_CreateWindow("Hello World!", 100, 100, viewportWidth, viewportHeight, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		logMessage("Window Error");
		SDL_Quit();
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // | SDL_RENDERER_PRESENTVSYNC
	if (renderer == nullptr) {
		logMessage("Renderer Error");
		SDL_Quit();
	}
	
	zeroLayer.texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, viewportWidth, viewportHeight);
	SDL_SetTextureBlendMode(zeroLayer.texture, SDL_BLENDMODE_BLEND);
}

void Engine::Graphics::deinitialize() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

extern struct Engine::Graphics::RenderLayer *Engine::Graphics::getRenderLayer(int zIndex_) {
	struct RenderLayer *iLayer = &zeroLayer;
	struct RenderLayer *temp;
	bool layerExists = false;
	while (true) {
		if (iLayer->index == zIndex_) {
			layerExists = true;
			break;
		}

		if (iLayer->next == NULL) {
			break;
		}

		if (iLayer->next->index > zIndex_) {
			break;
		}
		iLayer = iLayer->next;
	}
	//This spaghetti inserts a new renderLayer after the iterator
	if (!layerExists) {
		temp = iLayer->next;
		iLayer->next = new struct RenderLayer;
		iLayer->next->index = zIndex_;
		iLayer->next->next = temp;
		iLayer->next->texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, viewportWidth, viewportHeight);
		SDL_SetTextureBlendMode(iLayer->next->texture, SDL_BLENDMODE_BLEND);
		logMessage("Render Layer Created");
		iLayer = iLayer->next;
	}
	return iLayer;
}

SDL_Renderer *Engine::Graphics::getRenderer() {
	return renderer;
}

void Engine::Graphics::draw(Camera * camera_, Sprite *sprite_, int x_, int y_, int width_, int height_, int frame_, int zIndex_) {

	SDL_Rect dstrect;
	dstrect.x = x_ - camera_->getX();
	dstrect.y = y_ - camera_->getY();
	dstrect.w = width_;
	dstrect.h = height_;

	//find or create the correct renderlayer
	struct RenderLayer *layer = getRenderLayer(zIndex_);

	SDL_SetRenderTarget(renderer, layer->texture); //sets the render target to a texture
	if (sprite_) {
		SDL_Rect srcrect;
		srcrect.x = sprite_->getFrameWidth() * frame_;
		srcrect.y = 0;
		srcrect.w = sprite_->getFrameWidth();
		srcrect.h = sprite_->getFrameHeight();
		SDL_RenderCopy(renderer, sprite_->getTexture(), &srcrect, &dstrect); //render to the texture
	}
	else { 	//draw a purple rectangle
		SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
		SDL_RenderDrawRect(renderer, &dstrect);
	}
	SDL_SetRenderTarget(renderer, NULL); //reset the render target to the renderer
}

void Engine::Graphics::flipBuffer() {
	SDL_RenderClear(renderer); //clears the renderer
	struct RenderLayer *i = &zeroLayer;
	while (i != NULL) {
		SDL_RenderCopy(renderer, i->texture, NULL, NULL); //blits the texture to the renderer
		SDL_SetRenderTarget(renderer, i->texture); //sets the render target to the texture
		SDL_RenderClear(renderer); //clears the texture
		SDL_SetRenderTarget(renderer, NULL); //resets the render target
		i = i->next;
	}
	SDL_RenderPresent(renderer);
}