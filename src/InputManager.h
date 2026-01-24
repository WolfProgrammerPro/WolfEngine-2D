#pragma once


#define X_JOYSTICK_PIN A0
#define Y_JOYSTICK_PIN A1

#include <GameObject.h>
#include <Arduino.h>

class InputManager
{
    public:
        Vector2 getJoystickRotation() const {return Vector2{analogRead(X_JOYSTICK_PIN), analogRead(Y_JOYSTICK_PIN)};}

};
