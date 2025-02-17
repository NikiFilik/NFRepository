#include <iostream>
#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "functions.hpp"

int main()
{
    srand(time(NULL));

    int n;
    nf::userInput(n);
    nf::Game myGame(1600, 900, "My First Game!");
    myGame.setup(n);
    myGame.lifeCycle();
    myGame.end();
    return 0;
}