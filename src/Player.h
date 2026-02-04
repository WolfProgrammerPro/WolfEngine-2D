#pragma once
#include <DinamicObject.h>
#include <PlayerCollider.h>
#include <PlayerMovement.h>
#include <Renderer.h>
#include <Utils.h>



class Player
{
    public:
        Player() : gameObject(Vector2{0,0}, Vector2{0,0}, PLAYER), playerCollider(gameObject), playerMovement(gameObject) {};
        Player(Vector2 pos, Vector2 _size) : gameObject(pos, _size, PLAYER), playerCollider(gameObject), playerMovement(gameObject) {};
        void update(Renderer& renderer, MapsManager& mapsManager);
        DinamicObject& getGameObject()  {return gameObject;}
    private:
        DinamicObject gameObject;
        PlayerCollider playerCollider;
        PlayerMovement playerMovement;
};