#pragma once
#include <string>
#include <SFML/Graphics.hpp>

#include "Circle.hpp"


namespace nf {
	class Game {
	private:
		int width, height;
		std::string title;
		sf::RenderWindow window;
		nf::Circle* circleArr;
		int cnt;
	public:
		Game(int width, int height, std::string title);
		void setup(int n);
		void lifeCycle();
		void end();
	};
}