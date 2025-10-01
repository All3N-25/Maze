#include "../Headers/Grid.hpp"
#include "../Headers/Wall.hpp"

Grid::Grid(int rows, int collumns, int size)
{
    this->rows = rows;
    this->collumns = collumns;
    this->size = size;

    Initialize();
}

void Grid::Initialize()
{
    grid.resize(rows, std::vector<Wall>(collumns, Wall(0,0,size,false,false,false,false)));

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < collumns; c++)
        {
            // At the start, every cell has all four walls
            grid[r][c] = Wall(r, c, size, true, true, true, true);
        }
    }
}

void Grid::Draw(sf::RenderWindow& window)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < collumns; c++)
        {
            grid[r][c].Draw_Wall_Step(window);
        }
    }
}

int Grid::getRows()
{
    return rows;
}

int Grid::getCollumns()
{
    return collumns;
}

Wall& Grid::getCell(int row, int col) 
{ 
    return grid[row][col]; 
}