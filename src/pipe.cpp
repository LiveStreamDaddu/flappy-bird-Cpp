#include "pipe.h"


Pipe::Pipe()
{
    Image image = LoadImage("Graphics/pipe-green.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

Pipe::~Pipe()
{
    UnloadTexture(texture);
}

void Pipe::Draw()
{
    DrawTextureEx(texture , {200 , 400} , 0 , 1.5f , WHITE);
    DrawTextureEx(texture , {280 , 280} , 180 , 1.5f , WHITE);
}
