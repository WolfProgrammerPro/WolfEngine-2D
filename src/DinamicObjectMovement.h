#pragma once

#include <MapsManager.h>
#include <DinamicObject.h>
#include <Physics.h>
#include <Arduino.h>

class DinamicObjectMovement
{
public:
    DinamicObjectMovement(DinamicObject& object, Vector2 positionOnReset, unsigned long cooldown);
    void updatePosition(MapsManager& mapsManager);
    void resetPosition();
protected:
    DinamicObject& gameObject;
    Physics physics;
    Vector2 starterPositionOnReset;
    void moveTo(MapsManager& mapsManager, Vector2 position);
    bool hasLetToObjectMove(MapsManager& mapsManager, Vector2 newObjectPosition);
    virtual Vector2 getMovementDirection();
    unsigned long lastMove = 0;
    unsigned long moveCooldown;
};