#pragma once
#include "bird.h"
#include "pipe.h"

class Game
{
    public:
        Game();
        void Draw();
        void Update();
    private :
        Bird bird;
        // Pipe pipe;
};