#pragma once

#include <Physics.h>
#include <GameObject.h>
#include <GameManager.h>

class PlayerCollider
{
    public:
        PlayerCollider(Player& _player) : player(_player) {};
        void checkCollisions(Renderer& renderer, MapsManager& mapsManager,PlayerMovement& playerMovement);
    private:
        Player& player;
        Physics playerPhysics;
        GameManager gameManager;
};