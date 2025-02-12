#include <iostream>
#include <string>

const int SCREEN_WIDTH = 1920, SCREEN_HEIGHT = 1080;

class Point2d {
private:
	int x, y;
public:
	Point2d(int x, int y){
		setX(x);
		setY(y);
	}

	void setX(int x) {
		if (x < 0 || x >= SCREEN_WIDTH) {
			std::cerr << "ERROR: Invalid x value\n";
			return;
		}
		this->x = x;
	}
	void setY(int y) {
		if (y < 0 || y >= SCREEN_HEIGHT) {
			std::cerr << "ERROR: Invalid y value\n";
			return;
		}
		this->y = y;
	}

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}

	std::string asString() {
		return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
	}
};

class Vector2d {
private:
	int x, y;
public:
	Vector2d(int x, int y): x(x), y(y) {

	}

	Vector2d(Point2d p): x(p.getX()), y(p.getY()) {

	}

	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};

int main() {

	return 0;
}