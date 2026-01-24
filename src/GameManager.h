#pragma once

#include <GameObject.h>
#include <Renderer.h>
#include <MapsManager.h>
#include <PlayerMovement.h>

class GameManager
{
    public:
        void removeAllObjectsWithId(MapsManager& mapsManager, unsigned short id, Renderer& renderer);
        void finishLevel(MapsManager& MapsManager, Renderer& renderer, PlayerMovement& playerMovement);
    private:
};