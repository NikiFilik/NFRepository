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
		triangleArr = new nf::Triangle[cnt];
		rectangleArr = new nf::Rectangle[cnt];
		lineArr = new nf::Line[cnt];

		for (int i = 0; i < cnt; i++) {
			circleArr[i].setup(rand() % width, rand() % height, rand() % 90 + 10);
			triangleArr[i].setup(rand() % width, rand() % height, rand() % 90 + 10);
			rectangleArr[i].setup(rand() % width, rand() % height, rand() % 180 + 20, rand() % 180 + 20);
			lineArr[i].setup(rand() % width, rand() % height, rand() % width, rand() % height);
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
				window.draw(triangleArr[i].getShape());
				window.draw(rectangleArr[i].getShape());
				window.draw(lineArr[i].getShape(), 2, sf::Lines);
			}

			window.display();
		}
	}
	void Game::end() {
		delete[] circleArr;
		delete[] triangleArr;
		delete[] rectangleArr;
		delete[] lineArr;
	}
}