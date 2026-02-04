#pragma once

#include <Arduino.h>
#include <MapsManager.h>
#include <DinamicObjectMovement.h>

class GameManager
{
public:
    void removeAllObjectsWithId(MapsManager& mapsManager, unsigned short id, Renderer& renderer);
    void finishLevel(MapsManager& mapsManager, Renderer& renderer, DinamicObjectMovement& objectMovement);
};