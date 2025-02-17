#pragma once

#include <SFML/Graphics.hpp>

namespace nf {
	class Rectangle {
	private:
		float x, y;
		float a, b;
		sf::RectangleShape shape;
	public:
		Rectangle() = default;
		Rectangle(float x, float y, float a, float b);
		void setup(float x, float y, float a, float b);
		sf::RectangleShape getShape();
	};
}