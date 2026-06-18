#pragma once
#include "grid.hpp" 

class Simulation
{

private:

    Grid grid;
    Grid tempGrid;
    bool run;

public:

    Simulation(int width, int height, int cellSize) 
    : grid(width, height, cellSize), tempGrid(width, height, cellSize), run(false) {grid.FillRandom(); };

    void Draw();
    void SetCellValue(int row, int col, int value);
    int CountLiveNeighbours(int row, int col);
    void Update(); 
    bool IsRunning() { return run; }

    void StartSimulation() { run = true; }
    void StopSimulation() { run = false; }
};