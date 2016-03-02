#include "stdafx.h"
#include "PlayerSprite.h"
#include "Game.h"
#include "InputController.h"

PlayerSprite::PlayerSprite() : _velocity(0.0f), _maxVelocity(.3f), _acceleration(.0005f), _moving(false)
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
		_moving = true;
		InputController::moveLeft(_velocity, _acceleration, elapsedTime);
		std::cout << _velocity << " " << _acceleration << " " << elapsedTime << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		_moving = true;
		InputController::moveRight(_velocity, _acceleration, elapsedTime);
		std::cout << _velocity << " " << _acceleration << " " << elapsedTime << std::endl;
	}
	else
	{
		_velocity = 0.0f;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_velocity = 0.0f;
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
	getSprite().move(_velocity * elapsedTime, 0.0f);
}