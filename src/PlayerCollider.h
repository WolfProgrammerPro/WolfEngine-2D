#pragma once

#include <Collider.h>
#include <Arduino.h>



class PlayerCollider : public Collider
{
public:
    PlayerCollider(DinamicObject& player) : Collider(player) {};
    void checkCollisions(Renderer& renderer, MapsManager& mapsManager, DinamicObjectMovement& objectMovement) override;
};