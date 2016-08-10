#include "Camera.h"


Engine::Camera::Camera(int viewPortWidth_, int viewPortHeight_) {
	width = viewPortWidth_;
	height = viewPortHeight_;
	x = 0;
	y = 0;
	hasBounds = false;
	boundMinX = 0;
	boundMinY = 0;
	boundMaxX = 0;
	boundMaxY = 0;
}


Engine::Camera::~Camera() {
}

int Engine::Camera::getX() {
	return x;
}

int Engine::Camera::getY() {
	return y;
}

void Engine::Camera::setX(int x_) {
	x = x_;
}
void Engine::Camera::setY(int y_) {
	y = y_;
}

void Engine::Camera::centerOnPoint(int x_, int y_) {
	x = x_ - (width / 2);
	y = y_ - (height / 2);
}
