#include <iostream>
#include <SFML/Graphics.hpp>
#include "Headers/Grid.hpp"
#include "Headers/Generator.hpp"

using namespace std;

int main()
{
    uint16_t window_width = 602;
    uint16_t window_height = 602;

    uint16_t windowPosX = (2560 - window_width) / 2;
    uint16_t windowPosY = (1440 - window_height) / 2;

    sf::RenderWindow window(sf::VideoMode({window_width, window_height}), "Maze", sf::Style::Default);

    window.setPosition(sf::Vector2i(windowPosX, windowPosY));
    window.setFramerateLimit(60);

    sf::Event event;

    Grid grid(30, 30, 20);

    Generator gen(grid);
    gen.DFS(0,0);

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