#pragma once
namespace Engine {
	class Camera {
	private:
		int x, y, width, height;
		bool hasBounds;
		int boundMinX, boundMinY, boundMaxX, boundMaxY;
	public:
		Camera(int viewPortWidth_, int viewPortHeight_);
		~Camera();
		int getX();
		int getY();
		void setX(int x_);
		void setY(int y_);
		void centerOnPoint(int x_, int y_);
		void setBounds(int minX_, int minY_, int maxX_, int maxY_); //the camera will never pass outside of these bounds. Default unset.
		void unsetBounds(); //removes camera boundaries
	};
}
