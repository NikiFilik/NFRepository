#pragma once
#include <SFML/Graphics.hpp>

namespace nf {
	class Circle {
	private:
		float px, py;
		float r;
		float vx, vy;
		sf::CircleShape shape;
	public:
		Circle() = default;
		Circle(float x, float y, float r);

		void setup(float x, float y, float r);

		void updatePosition(float dt);

		void leftWallCollisionDetector();
		void rightWallCollisionDetector(int width);
		void upWallCollisionDetector();
		void downWallCollisionDetector(int height);

		sf::CircleShape getShape();
	};
}