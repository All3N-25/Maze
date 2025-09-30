#pragma once
#include <SFML/Graphics.hpp>

class Wall
{
    private:
        bool top, left, bot, right;
        int row, col, size;

        sf::RectangleShape top_wall;
        sf::RectangleShape left_wall;
        sf::RectangleShape bot_wall;
        sf::RectangleShape right_wall;

    public:

        Wall(int row, int col, int size, bool top, bool left, bool bot, bool right);

        void Initialize_Wall(int row, int col, int size, bool top, bool left, bool bot, bool right);
        void Draw_Wall(sf::RenderWindow& window);
};