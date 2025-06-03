#include "game.h"



Game::Game()
{
    
}

void Game::Draw()
{
    bird.Draw();
    // pipe.Draw();
}

void Game::Update()
{
    bird.Update();
}