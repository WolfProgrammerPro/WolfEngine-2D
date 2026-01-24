#pragma once

#include <Arduino.h>

enum GameObjectType
{
    NONE,
    WALL,
    PLAYER,
    KEY,
    DOOR,
    FINISH
};


struct Vector2
{
    int x;
    int y;
    bool operator==(const Vector2& other) const {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Vector2& other) const {
        return x != other.x || y != other.y;
    }
    Vector2 operator+(const Vector2& other) const {
        Vector2 result;
        result.x = x + other.x;
        result.y = y + other.y;
        return result;
    }
};


class GameObject{
    private:
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wreorder"
        GameObjectType type;
        
        unsigned short id;
        bool active;
        #pragma GCC diagnostic pop
    public:
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wreorder"
        GameObject() : type(NONE), position({0,0}), id(0), active(false) {};
        GameObject(Vector2 pos, GameObjectType _type = WALL, unsigned short _id = 0) : position(pos), type(_type), id(_id), active(true) {};
        #pragma GCC diagnostic pop
        Vector2 getPosition() const {return position;}
        GameObjectType getType() const {return type;}
        bool isActive() const {return active;}
        unsigned short getId() const {return id;}
        inline void setActive(bool newValue) {active = newValue;}
    
    protected:
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wreorder"
        Vector2 position; 
        #pragma GCC diagnostic pop
};

