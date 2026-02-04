#include <GameManager.h>

void GameManager::removeAllObjectsWithId(MapsManager& mapsManager, unsigned short id, Renderer& renderer)
{
    for (unsigned int i = 0; i < mapsManager.getCurrentMapSize(); i++)
    {
        GameObject& object = mapsManager.getCurrentMap()[i];
        if (object.getId() == id)
        {
            object.setActive(false);
            renderer.renderObject(object);
        }
    }
    
}

void GameManager::finishLevel(MapsManager& mapsManager, Renderer& renderer, DinamicObjectMovement& objectMovement)
{
    mapsManager.nextMap(renderer);
    objectMovement.resetPosition();
}