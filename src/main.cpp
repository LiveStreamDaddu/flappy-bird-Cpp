#include <raylib.h>
#include "game.h"
#include <iostream>
#include <deque>

int main() 
{

    
    int frameCount = 0;
    bool gameOver = false;
    
    constexpr int screenWidth = 300;
    constexpr int screenHeight = 550;
    
    
    
    InitWindow(screenWidth, screenHeight, "Flappy Bird");
    SetTargetFPS(60);
    //Game game = Game();
    Bird bird ;
    std::deque<Pipe> pipes;
    Texture2D backgroundTexture = LoadTextureFromImage(LoadImage("Graphics/background-day.png"));
    Texture2D baseTexture = LoadTextureFromImage(LoadImage("Graphics/base.png"));
    
    
    while (!WindowShouldClose())
    {
        
        
        BeginDrawing();
            ClearBackground(BLACK);

            DrawTextureEx(backgroundTexture , {0.0f,0.0f} , 0.0f , 1.1f , WHITE);
            

            if(!gameOver)
            {
                bird.Update();

                DrawTextureEx(baseTexture , {0.0f,480.0f} , 0.0f , 1.1f , WHITE);

                if(frameCount % 120 == 0)
                {
                    pipes.push_back(Pipe(300));
                }

                for(Pipe& pipe : pipes)
                {
                    pipe.Draw(); 
                    pipe.Update();
                    
                }
            
                bird.Draw();
                frameCount++;
            }
            
        EndDrawing();
    }
    
    CloseWindow();
}