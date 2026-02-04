#pragma once

#include <InputManager.h>
#include <Physics.h>
#include <Utils.h>
#include <DinamicObjectMovement.h>

class PlayerMovement : public DinamicObjectMovement
{
    public:
        PlayerMovement(DinamicObject& player) : DinamicObjectMovement(player, Vector2{STARTER_PLAYER_POSITION_X, STARTER_PLAYER_POSITION_Y}, JOYSTICK_READ_MINIMAL_COOLDOWN) {};
    private:
        InputManager inputManager;
        Vector2 getMovementDirection() override;
};