#include "Circle.hpp"

namespace nf {
	Circle::Circle(float x, float y, float r) {
		setup(x, y, r);
	}

	void Circle::setup(float x, float y, float r) {
		px = x;
		py = y;
		this->r = r;
		shape.setRadius(r);
		shape.setOrigin(r, r);
		shape.setPosition(x, y);

		vx = rand() % 201 - 100;
		vy = rand() % 201 - 100;

		shape.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 255));
	}

	void Circle::updatePosition(float dt) {
		px += vx * dt;
		py += vy * dt;
		shape.setPosition(px, py);
	}
	void Circle::leftWallCollisionDetector() {
		if (px - r <= 0) {
			vx = -vx;
		}
	}
	void Circle::rightWallCollisionDetector(int width) {
		if (px + r >= width) {
			vx = -vx;
		}
	}
	void Circle::upWallCollisionDetector() {
		if (py - r <= 0) {
			vy = -vy;
		}
	}
	void Circle::downWallCollisionDetector(int height) {
		if (py + r >= height) {
			vy = -vy;
		}
	}

	sf::CircleShape Circle::getShape() {
		return shape;
	}
}