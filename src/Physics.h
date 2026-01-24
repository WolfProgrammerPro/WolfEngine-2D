#pragma once

#include <GameObject.h>
#include <Player.h>
#include <MapsManager.h>

class Physics
{
    public:
    GameObject getCollision(MapsManager& mapsManager,GameObject& object);
    bool hasObjectOnThisPosition(MapsManager& mapsManager, Vector2 position);
}; 