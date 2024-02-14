#include "Circle.hpp"

namespace nf {
	Circle::Circle(float x, float y, float r) {
		this->x = x;
		this->y = y;
		this->r = r;
		shape.setRadius(r);
		shape.setOrigin(r, r);
		shape.setPosition(x, y);
		shape.setFillColor(sf::Color(255, 0, 0, 255));
	}

	sf::CircleShape Circle::getShape() {
		return shape;
	}
}