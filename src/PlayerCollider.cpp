#include <PlayerCollider.h>


void PlayerCollider::checkCollisions(Renderer& renderer, MapsManager& mapsManager,DinamicObjectMovement& objectMovement)
{
    
    GameObject collision = physics.getCollision(mapsManager, gameObject);
    if (collision.isActive() == true && collision.getType() != NONE)
    {
        if (collision.getType() == KEY) {gameManager.removeAllObjectsWithId(mapsManager, collision.getId(), renderer);}
        if (collision.getType() == FINISH) {gameManager.finishLevel(mapsManager, renderer, objectMovement);}
    }
}