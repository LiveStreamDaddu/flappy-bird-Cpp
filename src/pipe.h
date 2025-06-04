#pragma once
#include <raylib.h>
#include "bird.h"

class Pipe
{
    public:
        Pipe(float startX , float gapY , float y);
        void Draw();
        float gapY;
        float x;
        float y;
        float speed;
        void Update();
        bool CollidesWithBird(const Bird& bird);
    private:
        Texture2D texture;
};