#include "pipe.h"


Pipe::Pipe(float startX)
{
    Image image = LoadImage("Graphics/pipe-green.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);

    gapY = GetRandomValue(200 , 400);
    x = startX;
    speed = 3;
}



void Pipe::Draw()
{
    DrawTextureEx(texture , {x , 400} , 0 , 1.5f , WHITE);
    DrawTextureEx(texture , {x + 80 , 280} , 180 , 1.5f , WHITE);
}

void Pipe::Update()
{
    x -= speed;
}
