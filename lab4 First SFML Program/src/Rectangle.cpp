#include "Rectangle.hpp"

namespace nf {
	Rectangle::Rectangle(float x, float y, float a, float b) {
		setup(x, y, a, b);
	}

	void Rectangle::setup(float x, float y, float a, float b) {
		this->a = a;
		this->b = b;
		this->x = x;
		this->y = y;
		shape.setSize(sf::Vector2f(a, b));
		shape.setOrigin(a / 2, b / 2);
		shape.setPosition(x, y);
		shape.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 127));
		shape.setRotation(rand() % 180);
	}

	sf::RectangleShape Rectangle::getShape() {
		return shape;
	}
}