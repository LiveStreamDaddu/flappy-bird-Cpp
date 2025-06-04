#include <raylib.h>
#include "bird.h"
#include "pipe.h"
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

    Bird bird = Bird() ;

    std::deque<Pipe> pipes;

    Image bgImage = LoadImage("Graphics/background-day.png");
    Texture2D backgroundTexture = LoadTextureFromImage(bgImage);
    UnloadImage(bgImage);

    Image baseImage = LoadImage("Graphics/base.png");
    Texture2D baseTexture = LoadTextureFromImage(baseImage);
    UnloadImage(baseImage);

    int score = 0;
    
    while (!WindowShouldClose())
    {
        
        
        BeginDrawing();
            ClearBackground(BLACK);
            DrawTextureEx(backgroundTexture , {0.0f,0.0f} , 0.0f , 1.1f , WHITE);
            

            if(!gameOver)
            {
                bird.Update();
                int gapY;
                int y;

                if(frameCount % 125 == 0)
                {
                    gapY = GetRandomValue(120 , 150);
                    y = GetRandomValue(80 , 200);
                    pipes.push_back(Pipe(300 , gapY,  y));
                }

                if((frameCount + 25)%120 == 0)
                {
                    score++;
                }   

                for(Pipe& pipe : pipes)
                {
                    pipe.Draw(); 
                    pipe.Update();
                    if(pipe.CollidesWithBird(bird))
                    {
                        gameOver = true;
                        score = 0;
                    }
                }

                DrawTextureEx(baseTexture , {0.0f,480.0f} , 0.0f , 1.1f , WHITE);
                DrawText(TextFormat("%i" , score) , 20 , 510 , 30 , WHITE);

                bird.Draw();
                frameCount++;
            }
            
        EndDrawing();
    }
    
    CloseWindow();
}