#include "bird.h"

Bird::Bird()
{
    Image image = LoadImage("Graphics/yellowbird-upflap.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    xPos = 120;
    yPos = 300;
    velocity = 0;
    gravity = 0.5f;
    jumpStrength = -8.0f;
}

Bird::~Bird()
{
    UnloadTexture(texture);
}

void Bird::Draw()
{
    DrawTextureEx(texture, {xPos, yPos}, 0.0f, 1.5f, WHITE);

}

void Bird::Update()
{
    velocity += gravity;
    yPos += velocity;
    if(IsKeyPressed(KEY_SPACE))
    {
        velocity = jumpStrength;
    }
    
}