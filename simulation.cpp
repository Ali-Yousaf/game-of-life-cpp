#include "simulation.hpp"
#include <vector>
#include <utility>
using namespace std;

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::SetCellValue(int row, int col, int value)
{
    grid.SetValue(row, col, value);
}

int Simulation::CountLiveNeighbours(int row, int col)
{
    int liveNeighbours = 0;
    vector<pair<int, int>> neighbourOffset =
    {
        {-1, 0},    // directly above
        {1, 0},     // directly below
        {0, -1},    // left
        {0, 1},     // right
        {-1, -1},   // up left
        {-1, 1},    // up right
        {1, -1},    // low left
        {1, 1}      // low right
    };

    for(const auto& offset : neighbourOffset)
    {
        int neighbourRow = (row + offset.first + grid.GetRows()) % grid.GetRows();
        int neighbourCol = (col + offset.second + grid.GetColumns()) % grid.GetColumns();
        
        liveNeighbours += grid.GetCellValue(neighbourRow, neighbourCol);
    }

    return liveNeighbours;
}

void Simulation::Update()
{
    if(IsRunning())
    {
        for(int row = 0; row < grid.GetRows(); row++)
        {
            for(int col = 0; col < grid.GetColumns(); col++)
            {
                int liveNeighbours = CountLiveNeighbours(row, col);
                int cellValue = grid.GetCellValue(row, col);

                if(cellValue == 1)
                {
                    if(liveNeighbours > 3 || liveNeighbours < 2)
                    {
                        tempGrid.SetValue(row, col, 0);
                    }

                    else
                    {
                        tempGrid.SetValue(row, col, 1);
                    }
                }

                else
                {
                    if(liveNeighbours == 3)
                    {
                        tempGrid.SetValue(row, col, 1);
                    }

                    else
                    {
                        tempGrid.SetValue(row, col, 0);
                    }
                }
            }
        }
        grid = tempGrid;
    }
}