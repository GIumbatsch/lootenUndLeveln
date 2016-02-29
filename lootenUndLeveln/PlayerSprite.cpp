#include "stdafx.h"
#include "PlayerSprite.h"
#include "Game.h"

PlayerSprite::PlayerSprite() : _velocity(0.0f), _maxVelocity(.3f), _acceleration(.005f)
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
		//_velocity -= 30.0f;
		_velocity = _velocity - 0.5f * _acceleration * (elapsedTime * elapsedTime);
		std::cout << _velocity << " " << _acceleration << " " << elapsedTime << std::endl;
	}
	
	if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		_velocity = 0.0f;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		//	_velocity += 30.0f;
		_velocity = _velocity + 0.5f * _acceleration * (elapsedTime * elapsedTime);
		std::cout << _velocity << " " << _acceleration << " " << elapsedTime << std::endl;
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