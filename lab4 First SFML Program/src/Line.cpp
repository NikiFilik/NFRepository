#include "Line.hpp"

namespace nf {
	Line::Line(float x1, float y1, float x2, float y2) {
		setup(x1, y1, x2, y2);
	}

	void Line::setup(float x1, float y1, float x2, float y2) {
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
		line[0].position = sf::Vector2f(x1, y1);
		line[1].position = sf::Vector2f(x2, y2);
		line[0].color = sf::Color(rand() % 256, rand() % 256, rand() % 256, 127);
		line[1].color = line[0].color;
	}

	sf::Vertex* Line::getShape() {
		return line;
	}
}