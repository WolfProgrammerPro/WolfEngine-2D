#include <PlayerMovement.h>

 PlayerMovement::PlayerMovement(Player& _player) : player(_player)
 {
    //resetPlayer();
 }


void PlayerMovement::move(MapsManager& mapsManager)
{
    if (millis() - lastMove >= JOYSTICK_READ_MINIMAL_COOLDOWN)
    {
        lastMove = millis();
        movePlayer(mapsManager);
    }
}

void PlayerMovement::resetPlayer()
{
    player.setPosition(Vector2{STARTER_PLAYER_POSITION_X, STARTER_PLAYER_POSITION_Y});
}

void PlayerMovement::movePlayer(MapsManager& mapsManager)
{
    Vector2 movementDirection = getMovementDirection();
    Vector2 newPlayerPosition = player.getPosition() + movementDirection;
    
    if (!physics.hasObjectOnThisPosition(mapsManager, newPlayerPosition))
    {
        player.setPosition(newPlayerPosition);
    }
}



Vector2 PlayerMovement::getMovementDirection()
{
    int x = 0;
    int y = 0;
    Vector2 joystickRotation = inputManager.getJoystickRotation();
    
    
    if (joystickRotation.x >= 1024 / 2 + MINIMAL_JOYSTICK_DEVIATION_TO_MOVE)
    {
        x = 1;
    }
    else if (joystickRotation.x <= 1024 / 2 - MINIMAL_JOYSTICK_DEVIATION_TO_MOVE)
    {
        x = -1;
    }

    if (joystickRotation.y >= 1024 / 2 + MINIMAL_JOYSTICK_DEVIATION_TO_MOVE)
    {
        y = -1;
    }
    else if (joystickRotation.y <= 1024 / 2 - MINIMAL_JOYSTICK_DEVIATION_TO_MOVE)
    {
        y = 1;
    }

    
    return Vector2{x,y};

}