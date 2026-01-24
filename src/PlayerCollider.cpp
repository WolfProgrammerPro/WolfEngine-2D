#include <PlayerCollider.h>
#include <Arduino.h>

void PlayerCollider::checkCollisions(Renderer& renderer, MapsManager& mapsManager,PlayerMovement& playerMovement)
{
    
    GameObject collision = playerPhysics.getCollision(mapsManager, player);
    if (collision.isActive() == true && collision.getType() != NONE)
    {
        if (collision.getType() == KEY) {gameManager.removeAllObjectsWithId(mapsManager, collision.getId(), renderer);}
        if (collision.getType() == FINISH) {gameManager.finishLevel(mapsManager, renderer, playerMovement);}
    }
}