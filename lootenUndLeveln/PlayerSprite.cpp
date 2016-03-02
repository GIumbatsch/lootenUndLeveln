#include "stdafx.h"
#include "PlayerSprite.h"
#include "Game.h"
#include "InputController.h"

PlayerSprite::PlayerSprite() : _velocity(0.0f), _maxVelocity(.3f), _acceleration(.0005f), _jumping(false), _velY(0.0f)
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

	//std::cout << "PlayerSprite- Time: " << elapsedTime << std::endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		InputController::moveLeft(_velocity, _acceleration, elapsedTime);
		std::cout << _velocity << " " << _acceleration << " " << elapsedTime << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		InputController::moveRight(_velocity, _acceleration, elapsedTime);
		std::cout << _velocity << " " << _acceleration << " " << elapsedTime << std::endl;
	}
	else
	{
		_velocity = 0.0f;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (!_jumping)
		{
			_velY = -5.0f;
			_jumping = true;
			std::cout << _velY << " " << _jumping << std::endl;
		}
	}

	if (_jumping)
	{
		if ((int) _velY < (int) 5.0f)
		{
			_velY += 0.2f;
			std::cout << _velY << " 1. if in _jumping " << _jumping << std::endl;
		}
		if (_velY >= 5.0f) {
			std::cout << _velY << " 2. if in _jumping (vor zuweisung) " << _jumping << std::endl;
			_velY = 0.0f;
			_jumping = false;
			std::cout << _velY << " 2. if in _jumping (vor zuweisung) " << _jumping << std::endl;
		}
	}

	if (_velocity > _maxVelocity)
		_velocity = _maxVelocity;

	if (_velocity < -_maxVelocity)
		_velocity = -_maxVelocity;
	
	/*
	sf::Vector2f pos = this->getPosition();

	if (pos.x  < getSprite().getLocalBounds().width
	|| pos.x >(Game::SCREEN_WIDTH - getSprite().getLocalBounds().width))
	{
	_velocity = 0.0f; // Bounce by current velocity in opposite direction
	}
	*/

	//std::cout << elapsedTime << std::endl;
	getSprite().move(_velocity * elapsedTime, _velY);
}