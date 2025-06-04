#include "pipe.h"


Pipe::Pipe(float startX , float gapY , float y)
{
    Image image = LoadImage("Graphics/pipe-green.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);

    x = startX;
    speed = 3;

    this->gapY = gapY;
    this->y = y;
    
}



void Pipe::Draw()
{

    DrawTextureEx(texture , {x , y+gapY} , 0 , 1.5f , WHITE);
    DrawTextureEx(texture , {x + 80 , y} , 180 , 1.5f , WHITE);
}

void Pipe::Update()
{
    x -= speed;
}

bool Pipe::CollidesWithBird(const Bird& bird)
{
    if((bird.xPos + 45.0f >= x) && (bird.xPos <= (x+80)))
    {
        if(bird.yPos < y || bird.yPos + 42 > y+gapY)
        {
            return true;
        }
    }
    return false;
}
