#pragma once

#include <Player.h>
#include <InputManager.h>
#include <Physics.h>
#include <Utils.h>

class PlayerMovement
{
    public:
        PlayerMovement(Player& _player);
        void move(MapsManager& mapsManager);
        void resetPlayer();
    private:
        InputManager inputManager;
        Physics physics;
        Player& player;
        unsigned long lastMove;
        Vector2 getMovementDirection();
        void movePlayer(MapsManager& mapsManager);
        void checkCollision(MapsManager& mapsManager);
};