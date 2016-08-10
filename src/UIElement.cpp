#include "UIElement.h"

Engine::UIElement::UIElement() {
	for (int i = 0; i < MAX_CHILDREN; i++) {
		child[i] = NULL;
	}

	pMarginWidth = 0;
	backgroundColor = { 5, 10, 15, 20 };
	pWidth = 0;
	pHeight = 0;
	pX = 0;
	pY = 0;
	centered = false;
}


Engine::UIElement::~UIElement(){
	//kill all children here
	for (int i = 0; i < MAX_CHILDREN; i++) {
		if (child[i] != NULL) {
			delete(child[i]);
		}
	}
}

void Engine::UIElement::setChild(UIElement *child_) {
	for (int i = 0; i < MAX_CHILDREN; i++) {
		if (child[i] == NULL) {
			child[i] == child_;
		}
	}
}

void Engine::UIElement::setMargin(int pWidth_) { //creates a zone inside the element where nothing but the background color will cover
	pMarginWidth = pWidth_;
}

void Engine::UIElement::setBackgroundColor(SDL_Color color_) {
	backgroundColor = color_;
}

void Engine::UIElement::setPercentageSize(int pWidth_, int pHeight_) {
	pWidth = pWidth_;
	pHeight = pHeight_;
}

void Engine::UIElement::setPercentagePosition(int pX_, int pY_) {
	pX = pX_;
	pY = pX_;
}

void Engine::UIElement::setMinSize(int width_, int height_) {
	minWidth = width_;
	minHeight = height_;
}

int Engine::UIElement::getPercentagePositionX() {
	return pX;
}

int Engine::UIElement::getPercentagePositionY() {
	return pY;
}

int Engine::UIElement::getPercentageSizeWidth() {
	return pWidth;
}

int Engine::UIElement::getPercentageSizeHeight() {
	return pHeight;
}

SDL_Color Engine::UIElement::getBackgroundCOlor() {
	return backgroundColor;
}

bool Engine::UIElement::isCentered() {
	return centered;
}