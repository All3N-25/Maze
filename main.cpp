#include <iostream>
#include <SFML/Graphics.hpp>
#include "Headers/Grid.hpp"

using namespace std;

int main()
{
    uint16_t window_width = 600;
    uint16_t window_height = 600;

    uint16_t windowPosX = (2560 - window_width) / 2;
    uint16_t windowPosY = (1440 - window_height) / 2;

    sf::RenderWindow window(sf::VideoMode({window_width, window_height}), "Maze", sf::Style::Default);

    window.setPosition(sf::Vector2i(windowPosX, windowPosY));
    window.setFramerateLimit(60);

    sf::Event event;

    Grid grid(20, 20, 20);

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == event.Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        grid.Draw(window);
        
        
        window.display();
    }



    return 0;
}