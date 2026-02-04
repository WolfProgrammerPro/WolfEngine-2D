#pragma once

#include <GameObject.h>
#include <Arduino.h>
#include <MapsManager.h>

class Physics
{
public:
    GameObject getCollision(MapsManager& mapsManager, GameObject& object);
    bool hasLetToObjectMove(MapsManager& mapsManager, Vector2 position, Vector2 size);
};