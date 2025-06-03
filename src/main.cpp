#include <raylib.h>
#include "game.h"

int main() 
{
    const Color lightBlue = {135, 206, 235, 255};
    
    constexpr int screenWidth = 300;
    constexpr int screenHeight = 550;
    
    
    
    InitWindow(screenWidth, screenHeight, "Flappy Bird");
    SetTargetFPS(60);
    Game game = Game();
    Texture2D backgroundTexture = LoadTextureFromImage(LoadImage("Graphics/background-day.png"));
    Texture2D baseTexture = LoadTextureFromImage(LoadImage("Graphics/base.png"));
    
    while (!WindowShouldClose())
    {
        
        
        BeginDrawing();
            ClearBackground(lightBlue);
            DrawTextureEx(backgroundTexture , {0.0f,0.0f} , 0.0f , 1.1f , WHITE);
            game.Draw();
            DrawTextureEx(baseTexture , {0.0f,480.0f} , 0.0f , 1.1f , WHITE);
            
            
            game.Update();
        EndDrawing();
    }
    
    CloseWindow();
}