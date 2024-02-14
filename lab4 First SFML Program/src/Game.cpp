#include "Game.hpp"

namespace nf {
	Game::Game(int width, int height, std::string title) {
		this->width = width;
		this->height = height;
		this->title = title;
	}
	void Game::setup(int n) {
		cnt = n;

		circleArr = new nf::Circle[cnt];
		for (int i = 0; i < cnt; i++) {
			circleArr[i].setup(rand() % width, rand() % height, rand() % 100 + 25);
		}

		window.create(sf::VideoMode(width, height), title);
	}
	void Game::lifeCycle() {
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear(sf::Color::Black);

			for (int i = 0; i < cnt; i++) {
				window.draw(circleArr[i].getShape());
			}

			window.display();
		}
	}
	void Game::end() {
		delete[] circleArr;
	}
}