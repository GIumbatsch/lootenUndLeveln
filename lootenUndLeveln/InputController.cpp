#include "stdafx.h"
#include "InputController.h"

void InputController::moveLeft(float &velocity, float acceleration, float elapsedTime) {
	velocity = velocity - 0.5f * acceleration * (elapsedTime * elapsedTime);
}

void InputController::moveRight(float &velocity, float acceleration, float elapsedTime) {
	velocity = velocity + 0.5f * acceleration * (elapsedTime * elapsedTime);
}