#pragma once

#include <SFML/Graphics.hpp>

namespace nf {
	class Line {
	private:
		float x1, y1, x2, y2;
		sf::Vertex line[2];
	public:
		Line() = default;
		Line(float x1, float y1, float x2, float y2);
		void setup(float x1, float y1, float x2, float y2);
		sf::Vertex* getShape();
	};
}