#pragma once
#include "Engine.h"
#include "SDL.h"
#include <iostream>
namespace Engine {
	class UIElement {
	private:
		static const int MAX_CHILDREN = 8;
		UIElement *parent;
		UIElement *child[MAX_CHILDREN];
		int pX, pY, pWidth, pHeight; //x/y, w/h as percents of their containers.
		int minWidth, minHeight;
		SDL_Color backgroundColor; //background color
		int pMarginWidth;
		bool centered;

	public:
		UIElement(); //set parent here???
		~UIElement();
		void setChild(UIElement *child_);
		void setMargin(int pWidth_); //creates a zone inside the element where nothing but the background color will cover
		void setBackgroundColor(SDL_Color color_);
		void setPercentageSize(int pWidth_, int pHeight_);
		void setPercentagePosition(int pX_, int pY_);
		void setMinSize(int width_, int height_);
		//virtual void update() = 0;
		//virtual void draw() = 0;

		int getPercentagePositionX();
		int getPercentagePositionY();
		int getPercentageSizeWidth();
		int getPercentageSizeHeight();
		SDL_Color getBackgroundCOlor();
		int getMinWidth();
		int getMinHeight();
		bool isCentered();
	};
}