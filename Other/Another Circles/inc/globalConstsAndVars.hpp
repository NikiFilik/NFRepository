#pragma once

#include <SFML/Graphics.hpp>

namespace nf {
	const int WindowWidth = 1920, WindowHeight = 1080;

	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	
	const sf::Vector2f Gravity(0.f, 1000.f);
	const float EnviromentDensity = 1.f;
}