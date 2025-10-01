#include "../Headers/Generator.hpp"

Generator::Generator(Grid& g, int start_row, int start_col)
    : grid(g),
      rows(g.getRows()),
      cols(g.getCollumns()),
      rng(std::random_device{}()),
      done(false)
{
    Reset(start_row, start_col);
}

void Generator::Reset(int start_row, int start_col)
{
    visited.assign(rows, std::vector<bool>(cols, false));
    stack.clear();
    stack.emplace_back(start_row, start_col);
    visited[start_row][start_col] = true;
    done = false;
}

std::pair<int,int> Generator::GetCurrent() const
{
    if (stack.empty()) return {-1, -1};
    return stack.back();
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


void Generator::Remove_Wall_Step(int r1, int c1, int r2, int c2)
{
    Wall &a = grid.getCell(r1, c1);
    Wall &b = grid.getCell(r2, c2);

    int dr = r2 - r1;
    int dc = c2 - c1;

    if (dr == -1) {          // neighbor is above
        a.Set_Top(false);
        b.Set_Bot(false);
    } else if (dr == 1) {    // neighbor is below
        a.Set_Bot(false);
        b.Set_Top(false);
    } else if (dc == -1) {   // neighbor is left
        a.Set_Left(false);
        b.Set_Right(false);
    } else if (dc == 1) {    // neighbor is right
        a.Set_Right(false);
        b.Set_Left(false);
    }
}

// STEP BY STEP
void Generator::Step()
{
    if (done)
    {
        return;
    }

    if (stack.empty())
    {
        done = true;
        return;
    }

    auto [row, col] = stack.back();
    auto neighbors = Get_Unvisited_Neighbors(row, col);

        if (!neighbors.empty())
    {
        // pick a random neighbor
        std::uniform_int_distribution<int> dist(0, (int)neighbors.size() - 1);
        auto next = neighbors[dist(rng)];

        // remove the wall between current and chosen neighbor
        Remove_Wall_Step(row, col, next.first, next.second);

        // mark visited and push neighbor onto stack
        visited[next.first][next.second] = true;
        stack.push_back(next);
    }
    else
    {
        // backtrack
        stack.pop_back();
    }
}

bool Generator::Is_Done()
{
    return done;
}

void Generator::Save_Maze(Grid& grid, const std::string& filename) 
{
    std::ofstream file(filename);
    if (!file) return;

    int rows = grid.getRows();
    int cols = grid.getCollumns();

    file << rows << " " << cols << "\n";

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            Wall& w = grid.getCell(r,c);

            file 
                << w.Get_Top() << " "
                << w.Get_Left() << " "
                << w.Get_Bot() << " "
                << w.Get_Right();

            file << (c == cols - 1 ? '\n' : ' ');
        }
    }
}
void Generator::Load_Maze(Grid& grid, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return;

    int rows, cols;
    file >> rows >> cols;

    // (Optional) recreate grid if dimensions mismatch
    if (rows != grid.getRows() || cols != grid.getCollumns()) {
        std::cerr << "Grid size mismatch! Expected " 
                  << grid.getRows() << "x" << grid.getCollumns() 
                  << " but file has " << rows << "x" << cols << "\n";
        return;
    }

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int t, l, b, ri;
            file >> t >> l >> b >> ri;

            Wall& w = grid.getCell(r,c);
            w.Set_Top(t);
            w.Set_Left(l);
            w.Set_Bot(b);
            w.Set_Right(ri);
        }
    }
}
