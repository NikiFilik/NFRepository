#pragma once

#include <SFML/Graphics.hpp>

namespace nf {
	class Triangle {
	private:
		float x, y, r;
		sf::CircleShape shape;
	public:
		Triangle() = default;
		Triangle(float x, float y, float r);

		void setup(float x, float y, float r);

		sf::CircleShape getShape();
	};
}