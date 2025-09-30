#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

#include "Grid.hpp"

class Generator
{
    private:

        Grid& grid;

        int current_row;
        int current_col;

        std::vector<std::vector<bool>> visited;

    public:
        
        void DFS(int current_row, int current_col);

};