#include "Triangle.hpp"

namespace nf {
	Triangle::Triangle(float x, float y, float r) {
		setup(x, y, r);
	}

	void Triangle::setup(float x, float y, float r) {
		this->x = x;
		this->y = y;
		this->r = r;
		shape.setRadius(r);
		shape.setOrigin(r, r);
		shape.setPosition(x, y);
		shape.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 127));
		shape.setRotation(rand() % 120);
		shape.setPointCount(3);
	}

	sf::CircleShape Triangle::getShape() {
		return shape;
	}
}