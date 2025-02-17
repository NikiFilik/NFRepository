#pragma once

#include <SFML/Graphics.hpp>

#include "Object.hpp"

namespace nf {
	class Game {
	private:
		sf::RenderWindow mWindow;
		std::vector<nf::Object> mObjects;
	private:
		void processInput();
		void processPlayerInput(const sf::Keyboard::Key& key, const bool isPressed);

		void update(const sf::Time& deltaTime);

		void render();
	public:
		Game();
		void run();
	};
}