#include "Circle.hpp"

namespace nf {
	Circle::Circle(float x, float y, float r) {
		setup(x, y, r);
	}

	void Circle::setup(float x, float y, float r) {
		this->x = x;
		this->y = y;
		this->r = r;
		shape.setRadius(r);
		shape.setOrigin(r, r);
		shape.setPosition(x, y);
		shape.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 255));
	}

	sf::CircleShape Circle::getShape() {
		return shape;
	}
	float Circle::getX() {
		return x;
	}
	float Circle::getY() {
		return y;
	}
	float Circle::getR() {
		return r;
	}
}