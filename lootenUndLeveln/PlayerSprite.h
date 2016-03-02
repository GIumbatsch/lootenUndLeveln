#pragma once
#include "VisibleGameObject.h"

//Klasse für die Animation des Spielers
class PlayerSprite : public VisibleGameObject
{
public:
	PlayerSprite();
	~PlayerSprite();

	void update(float elapsedTime);
	void draw(sf::RenderWindow &rw);

	float getVelocity() const;

private:
	bool _moving;
	float _velocity;
	float _maxVelocity;
	float _acceleration;
};