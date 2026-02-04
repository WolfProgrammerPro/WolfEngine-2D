#include <Player.h>

void Player::update(Renderer& renderer, MapsManager& mapsManager)
{
    playerMovement.updatePosition(mapsManager);
    playerCollider.checkCollisions(renderer, mapsManager, playerMovement);
}