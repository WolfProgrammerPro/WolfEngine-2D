#pragma once

#include <GameObject.h>
#include <MapsManager.h>
#include <Physics.h>
#include <Utils.h>

class DinamicObject : public GameObject
{
public:
    DinamicObject() : GameObject() {};
    DinamicObject(Vector2 pos, Vector2 _size, GameObjectType _type, unsigned short _id = 0) : GameObject(pos, _size, _type, _id) {};
    void setPosition(Vector2 pos);
};