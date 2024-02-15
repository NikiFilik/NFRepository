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

		vx = rand() % 401 - 200;
		vy = rand() % 401 - 200;

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

	bool Circle::collisionDetector(Circle& other) {
		if ((px - other.px) * (px - other.px) + (py - other.py) * (py - other.py) <= (r + other.r) * (r + other.r)) {
			return true;
		}
		else {
			return false;
		}
	}

	void Circle::collisionProcess(Circle& other) {
		//https://www.vobarian.com/collisions/2dcollisions2.pdf
		float x1 = px, y1 = py, x2 = other.px, y2 = other.py;
		float nx = x2 - x1, ny = y2 - y1;
		float unx = nx / std::sqrt(nx * nx + ny * ny), uny = ny / std::sqrt(nx * nx + ny * ny);
		float utx = uny, uty = -unx;

		float v1x = vx, v1y = vy, v2x = other.vx, v2y = other.vy;

		float v1n = unx * v1x + uny * v1y, v1t = utx * v1x + uty * v1y;
		float v2n = unx * v2x + uny * v2y, v2t = utx * v2x + uty * v2y;

		float V1t = v1t, V2t = v2t;

		float m1 = r * r, m2 = other.r * other.r;
		float V1n = (v1n * (m1 - m2) + 2 * m2 * v2n) / (m1 + m2);
		float V2n = (v2n * (m2 - m1) + 2 * m1 * v1n) / (m1 + m2);

		float V1nx = V1n * unx, V1ny = V1n * uny;
		float V1tx = V1t * utx, V1ty = V1t * uty;
		float V2nx = V2n * unx, V2ny = V2n * uny;
		float V2tx = V2t * utx, V2ty = V2t * uty;

		float V1x = V1nx + V1tx, V1y = V1ny + V1ty;
		float V2x = V2nx + V2tx, V2y = V2ny + V2ty;

		vx = V1x;
		vy = V1y;
		other.vx = V2x;
		other.vy = V2y;
	}

	sf::CircleShape Circle::getShape() {
		return shape;
	}
}