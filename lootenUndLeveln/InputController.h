#pragma once
#include "stdafx.h"

class InputController {
public:
	InputController();
	~InputController();

	static void moveRight(float &velocity, float acceleration, float elapsedTime);
	static void moveLeft(float &velocity, float acceleration, float elapsedTime);
};