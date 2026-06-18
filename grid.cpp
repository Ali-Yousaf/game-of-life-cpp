#include "grid.hpp"
#include <raylib.h>

void Grid::Draw()
{
    for(int row = 0; row < rows; row++)
    {
        for(int column = 0; column < columns; column++)
        {
            Color color = cells[row][column] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
            DrawRectangle(column * cellSize, row * cellSize, cellSize - 1, cellSize - 1, color);
        }
    }
}

void Grid::SetValue(int row, int column, int value)
{
    if(isWithinBounds(row, column))
    {
        cells[row][column] = value;
    }
}

int Grid::GetCellValue(int row, int col)
{
    if(isWithinBounds(row, col))
    {
        return cells[row][col];
    }

    return 0; 
}

bool Grid::isWithinBounds(int row, int col)
{
    if(row >= 0 && row < rows && col >= 0 && col < columns)
    {
        return true;
    }

    return false;   
}

void Grid::FillRandom()
{
    for(int row = 0; row < rows; row++)
    {
        for(int col = 0; col < columns; col++)
        {
            int randomValue = GetRandomValue(0, 4);
            
            if(randomValue == 4)
                cells[row][col] = 1;

            else
                cells[row][col] = 0;
        }
    }
}