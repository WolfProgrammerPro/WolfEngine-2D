#include <Physics.h>
#include <Arduino.h>


GameObject Physics::getCollision(MapsManager& mapsManager, GameObject& object)
{
    for (unsigned int i = 0; i < MAX_GAME_OBJECTS_PER_LEVEL; i++)
    {
        GameObject& checkingObject = mapsManager.getCurrentMap()[i];
        
        if (checkingObject.getPosition() == object.getPosition() && checkingObject.isActive())
        {
            return checkingObject;
        }
    }
    return GameObject();
}

bool Physics::hasObjectOnThisPosition(MapsManager& mapsManager, Vector2 position)
{
    for (unsigned int i = 0; i < MAX_GAME_OBJECTS_PER_LEVEL; i++)
    {
        GameObject checkingObject = mapsManager.getCurrentMap()[i];

        if (checkingObject.getPosition() == position && checkingObject.getType() != NONE && checkingObject.isActive() && checkingObject.getType() != KEY && checkingObject.getType() != FINISH)
        {
            return true;
        }
    }
    return false;
}