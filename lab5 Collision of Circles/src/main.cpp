#include <iostream>
#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "functions.hpp"

int main()
{
    srand(time(NULL));

    int numberOfCircles;
    nf::userInput(numberOfCircles);

    nf::Game myGame(1600, 900, "Collision of Circles");

    myGame.setup(numberOfCircles);
    myGame.lifeCycle();
    myGame.end();

    return 0;
}