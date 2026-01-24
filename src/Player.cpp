#include <Player.h>

void Player::setPosition(Vector2 pos)
{
    if (pos.x >= 0 && pos.x < MAP_WIDTH  && pos.y >= 0 && pos.y < MAP_HEIGHT)
    {
        position = pos;
    }
}