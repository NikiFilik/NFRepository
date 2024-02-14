#include <iostream>
#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Circle.hpp"
#include "functions.hpp"

int main()
{
    nf::Circle myCircle(100, 100, 100);
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(myCircle.getShape());

        // end the current frame
        window.display();
    }
    return 0;
}