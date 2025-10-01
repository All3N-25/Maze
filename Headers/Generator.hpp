#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

#include "Grid.hpp"

class Generator
{
    private:

        Grid& grid;

        int rows;
        int cols;

        std::vector<std::vector<bool>> visited;

        std::mt19937 rng; 

    public:
        
        Generator(Grid& grid);
        void DFS(int current_row, int current_col);

        std::vector<std::pair<int,int>> Get_Unvisited_Neighbors(int row, int col);

        void Remove_Wall(Wall& current, Wall& neighbor, int dRow, int dCol);
};