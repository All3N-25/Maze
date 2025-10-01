#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <fstream>
#include <iostream>

#include "Grid.hpp"

class Generator
{
    private:

        Grid& grid;

        int rows;
        int cols;
        bool done;

        std::vector<std::vector<bool>> visited;
        std::vector<std::pair<int,int>> stack;

        std::mt19937 rng; 

        std::vector<std::pair<int,int>> Get_Unvisited_Neighbors(int row, int col);
        void Remove_Wall_Step(int r1, int c1, int r2, int c2);

        void Reset(int start_row, int start_col);

    public:
    
        Generator(Grid& grid, int start_row = 0, int start_col = 0);
        
        bool Is_Done();
        std::pair<int,int> GetCurrent() const;

        
        void Step();

        void Save_Maze(Grid& grid, const std::string& filename);
        void Load_Maze(Grid& grid, const std::string& filename);
};