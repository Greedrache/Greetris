#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(500, 620, "Greetris"); // Canvas for GameElements
    SetTargetFPS(60);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);

        DrawText("Score", 350, 15, 38, WHITE); // if font = DrawTextEx()
        DrawText("Next", 365, 175, 38, WHITE);
        if (game.gameOver)
        {
            DrawText("GAME OVER", 322, 450, 28, RED);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        int textWidth = MeasureText(scoreText, 38);
        int xCenter = 320 + (170 / 2) - (textWidth / 2);

        DrawText(scoreText, xCenter, 70, 38, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}