#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Wall.hpp"

class Grid
{
    protected:
        std::vector <std::vector<Wall>> grid;

        int rows;
        int collumns;
        int size;

        void Initialize();
        void Initialize_Walls(int row, int col);
        
    public:

        Grid(int width, int height, int size);
        void Draw(sf::RenderWindow& window);
};
