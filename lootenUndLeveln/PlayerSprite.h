#pragma once
#include "VisibleGameObject.h"

//Klasse f�r die Animation des Spielers
class PlayerSprite : public VisibleGameObject
{
public:
	PlayerSprite();
	~PlayerSprite();

	void update(float elapsedTime);
	void draw(sf::RenderWindow &rw);

	float getVelocity() const;

private:
	bool _jumping;
	float _velY;
	float _velocity;
	float _maxVelocity;
	float _acceleration;
};