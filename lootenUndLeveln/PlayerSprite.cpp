#include "stdafx.h"
#include "PlayerSprite.h"
#include "Game.h"

PlayerSprite::PlayerSprite() : _velocity(0.0f), _maxVelocity(.6f)
{
	load("images/PlayerPrototype.png");
	assert(isLoaded());

	getSprite().setOrigin(getSprite().getScale().x / 2, getSprite().getScale().y / 2);
}

PlayerSprite::~PlayerSprite()
{
}

void PlayerSprite::draw(sf::RenderWindow &rw)
{
	VisibleGameObject::draw(rw);
}

float PlayerSprite::getVelocity() const
{
	return _velocity;
}

void PlayerSprite::update(float elapsedTime)
{
	std::cout << "PlayerSprite- Time: " << elapsedTime << std::endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		std::cout << "Links gedrückt" << std::endl;
		//_velocity -= 30.0f;
		_velocity = -1 * _maxVelocity;
	
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		std::cout << "Rechts gedrückt" << std::endl;
		//	_velocity += 30.0f;
		_velocity = _maxVelocity;
	
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_velocity = 0.0f;
	}

	if (_velocity > _maxVelocity)
		_velocity = _maxVelocity;

	if (_velocity < -_maxVelocity)
		_velocity = -_maxVelocity;

	sf::Vector2f pos = this->getPosition();

	/*
	if (pos.x  < getSprite().getLocalBounds().width
		|| pos.x >(Game::SCREEN_WIDTH - getSprite().getLocalBounds().width ))
	{
		_velocity = 0; // Bounce by current velocity in opposite direction
	} */
	//std::cout << elapsedTime << std::endl;
	getSprite().move(_velocity * elapsedTime, 0.0f);
}