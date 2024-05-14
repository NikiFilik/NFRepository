#include "Game.hpp"

#include "globalConstsAndVars.hpp"

namespace nf {
	Game::Game(): 
		mWindow(sf::VideoMode(WindowWidth, WindowHeight), "RealBalls", sf::Style::Fullscreen) {
		mWindow.setVerticalSyncEnabled(true);
		mObjects.push_back(nf::Object(sf::Vector2f(660.f, 540.f), sf::Vector2f(0.f, 0.f), 50.f, 100.f, 0.9f, sf::Color(255, 255, 255)));
		mObjects.push_back(nf::Object(sf::Vector2f(1260.f, 540.f), sf::Vector2f(0.f, 0.f), 50.f, 10000.f, 0.9f, sf::Color(127, 127, 127)));
	}

	void Game::run() {
		sf::Clock clock;
		sf::Time timeSinceLastUpdate = sf::Time::Zero;
		sf::Time timeSinceLastFrame = sf::Time::Zero;

		while (mWindow.isOpen()) {
			timeSinceLastUpdate = clock.restart();
			timeSinceLastFrame += timeSinceLastUpdate;

			processInput();

			update(timeSinceLastUpdate);

			if (timeSinceLastFrame >= TimePerFrame) {
				timeSinceLastFrame = sf::Time::Zero;
				render();
			}
		}
	}

	void Game::processInput() {
		sf::Event event;
		while (mWindow.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::KeyPressed:
				processPlayerInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				processPlayerInput(event.key.code, false);
				break;
			}
		}
	}

	void Game::processPlayerInput(const sf::Keyboard::Key& key, const bool isPressed) {
		if (key == sf::Keyboard::Escape && isPressed) {
			mWindow.close();
		}
	}

	void Game::update(const sf::Time& deltaTime) {
		for (int i = 0; i < mObjects.size(); ++i) {
			if (mObjects[i].isCollidingWithTopWall()) {
				mObjects[i].ressolveCollisionWithTopWall();
			}
			if (mObjects[i].isCollidingWithBottomWall()) {
				mObjects[i].ressolveCollisionWithBottomWall();
			}
			if (mObjects[i].isCollidingWithLeftWall()) {
				mObjects[i].ressolveCollisionWithLeftWall();
			}
			if (mObjects[i].isCollidingWithRightWall()) {
				mObjects[i].ressolveCollisionWithRightWall();
			}
			mObjects[i].update(deltaTime);
		}
	}

	void Game::render() {
		mWindow.clear();

		for (int i = 0; i < mObjects.size(); ++i) {
			mWindow.draw(mObjects[i].getShape());
		}

		mWindow.display();
	}
}