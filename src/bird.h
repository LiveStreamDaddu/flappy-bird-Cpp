#pragma once
#include <raylib.h>

class Bird
{
    public:
        Bird();
        ~Bird();
        float velocity;
        float xPos;
        float yPos;
        float jumpStrength;
        void Draw();
        void Update();
        Texture2D texture;
    private:
        float gravity;
};