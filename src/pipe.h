#pragma once
#include <raylib.h>

class Pipe
{
    public:
        Pipe();
        ~Pipe();
        void Draw();
    private:
        Texture2D texture;
};