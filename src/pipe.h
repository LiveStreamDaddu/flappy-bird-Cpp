#pragma once
#include <raylib.h>

class Pipe
{
    public:
        Pipe(float startX);
        void Draw();
        float gapY;
        float x;
        float speed;
        void Update();
    private:
        Texture2D texture;
};