#include "../Headers/Generator.hpp"

Generator::Generator(Grid& grid) 
:  grid(grid), rows(grid.getRows()), cols(grid.getCollumns()) 
{
        visited.assign(rows, std::vector<bool>(cols, false));

        std::random_device rd;
        rng.seed(rd());
};

void Generator::DFS(int current_row, int current_col)
{
    visited[current_row][current_col] = true;

    std::vector<std::pair<int, int>> neighbors = Get_Unvisited_Neighbors(current_row, current_col);

    while(!neighbors.empty())
    {
        //Random Number
        std::uniform_int_distribution<int> dist(0, neighbors.size() - 1);
        int idx = dist(rng);

        auto [next_row, next_col] = neighbors[idx];

        Remove_Wall (grid.getCell(current_row, current_col),
                    grid.getCell(next_row, next_col),
                    next_row - current_row,
                    next_col - current_col
                    );
        
        DFS(next_row, next_col);

        neighbors = Get_Unvisited_Neighbors(current_row, current_col);
    }
}

std::vector<std::pair<int,int>> Generator::Get_Unvisited_Neighbors(int row, int col)
{
    std::vector<std::pair<int,int>> neighbors;

    if (row > 0 && !visited[row-1][col]) neighbors.push_back({row-1, col});
    if (row < rows-1 && !visited[row+1][col]) neighbors.push_back({row+1, col});
    if (col > 0 && !visited[row][col-1]) neighbors.push_back({row, col-1});
    if (col < cols-1 && !visited[row][col+1]) neighbors.push_back({row, col+1});

    return neighbors;
}

void Generator::Remove_Wall(Wall& current, Wall& neighbor, int dRow, int dCol)
{
    if (dRow == -1) { // neighbor is above
        current.Set_Top(false);
        neighbor.Set_Bot(false);
    }
    else if (dRow == 1) { // neighbor is below
        current.Set_Bot(false);
        neighbor.Set_Top(false);
    }
    else if (dCol == -1) { // neighbor is left
        current.Set_Left(false);
        neighbor.Set_Right(false);
    }
    else if (dCol == 1) { // neighbor is right
        current.Set_Right(false);
        neighbor.Set_Left(false);
    }
}