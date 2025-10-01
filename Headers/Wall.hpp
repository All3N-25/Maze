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

        void Set_Top(bool value);
        void Set_Left(bool value);
        void Set_Bot(bool value);
        void Set_Right(bool value);

        bool Get_Top();
        bool Get_Left();
        bool Get_Bot();
        bool Get_Right();
};