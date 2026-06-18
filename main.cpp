#include <iostream>
#include <raylib.h>
#include "simulation.hpp"

using namespace std;

// COLORS
Color COLOR_GREY = {29, 29, 29, 255};

const int SCREENW = 750;
const int SCREENH = 750;
const int CELL_SIZE = 25;

int FPS = 12;

enum Screen
{
    MENU,
    GAME
};

int main()
{
    InitWindow(SCREENW, SCREENH, "GAME OF LIFE");
    SetTargetFPS(FPS);

    Simulation simulation(SCREENW, SCREENH, CELL_SIZE);

    Screen currentScreen = MENU;

    while (!WindowShouldClose())
    {
        // =========================
        // UPDATE
        // =========================

        if (currentScreen == MENU)
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                currentScreen = GAME;
                SetWindowTitle("GAME OF LIFE");
            }
        }
        else if (currentScreen == GAME)
        {
            if (IsKeyPressed(KEY_BACKSPACE))
            {
                currentScreen = MENU;
                simulation.StopSimulation();
                SetWindowTitle("GAME OF LIFE");
            }

            if (IsKeyPressed(KEY_ENTER))
            {
                simulation.StartSimulation();
                SetWindowTitle("GAME OF LIFE (RUNNING)");
            }

            if (IsKeyPressed(KEY_SPACE))
            {
                simulation.StopSimulation();
                SetWindowTitle("GAME OF LIFE (STOPPED)");
            }

            if (IsKeyPressed(KEY_UP))
            {
                FPS += 2;
                SetTargetFPS(FPS);
            }

            if (IsKeyPressed(KEY_DOWN))
            {
                if (FPS > 5)
                {
                    FPS -= 2;
                    SetTargetFPS(FPS);
                }
            }

            simulation.Update();
        }

        // =========================
        // DRAW
        // =========================

        BeginDrawing();
        ClearBackground(BLACK);

        if (currentScreen == MENU)
        {
            const char* title = "GAME OF LIFE";
            int titleFontSize = 50;
            int titleWidth = MeasureText(title, titleFontSize);

            DrawText(
                title,
                (SCREENW - titleWidth) / 2,
                80,
                titleFontSize,
                GREEN
            );

            DrawText(
                "CONTROLS",
                (SCREENW - MeasureText("CONTROLS", 30)) / 2,
                180,
                30,
                WHITE
            );

            DrawText("ENTER  - Start Simulation", 180, 250, 25, WHITE);
            DrawText("SPACE  - Stop Simulation", 180, 290, 25, WHITE);
            DrawText("UP     - Increase Speed", 180, 330, 25, WHITE);
            DrawText("DOWN   - Decrease Speed", 180, 370, 25, WHITE);
            DrawText("BACKSPACE    - Return To Menu", 180, 410, 25, WHITE);

            DrawText(
                "Press ENTER To Start",
                (SCREENW - MeasureText("Press ENTER To Start", 30)) / 2,
                560,
                30,
                YELLOW
            );
        }
        
        else if (currentScreen == GAME)
        {
            simulation.Draw();
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}