#pragma once
#include <GameObject.h>
#include <Utils.h>

class Player : public GameObject
{
    public:
        Player() : GameObject(Vector2{0,0}, PLAYER) {};
        Player(Vector2 pos) : GameObject(pos, PLAYER) {};
        void setPosition(Vector2 pos);
};