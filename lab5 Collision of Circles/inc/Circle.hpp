#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

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

		bool collisionDetector(Circle& other);

		void collisionProcess(Circle& other);

		sf::CircleShape getShape();
	};
}