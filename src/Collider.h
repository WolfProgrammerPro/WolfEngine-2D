#pragma once

#include <Collider.h>
#include <DinamicObject.h>
#include <Renderer.h>
#include <MapsManager.h>
#include <DinamicObjectMovement.h>
#include <Physics.h>
#include <GameManager.h>

class Collider
{
public:
    Collider(DinamicObject& object) : gameObject(object) {};
    virtual void checkCollisions(Renderer& renderer, MapsManager& mapsManager, DinamicObjectMovement& objectMovement);
protected:
    DinamicObject& gameObject;
    Physics physics;
    GameManager gameManager;
};