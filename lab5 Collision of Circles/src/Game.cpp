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
			int r = rand() % 90 + 10;
			circleArr[i].setup(rand() % ((width - 20) - 2 * r) + r + 10, rand() % ((height - 20) - 2 * r) + r + 10, r);
		}

		window.create(sf::VideoMode(width, height), title);
	}
	void Game::lifeCycle() {
		clock.restart();
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear(sf::Color::Black);

			sf::Time dt = clock.restart();
			for (int i = 0; i < cnt; i++) {
				circleArr[i].leftWallCollisionDetector();
				circleArr[i].rightWallCollisionDetector(width);
				circleArr[i].upWallCollisionDetector();
				circleArr[i].downWallCollisionDetector(height);

				circleArr[i].updatePosition(dt.asSeconds());
				window.draw(circleArr[i].getShape());
			}

			window.display();
		}
	}
	void Game::end() {
		delete[] circleArr;
	}
}