#include "stdafx.h"
#include "GameObjectManager.h"
#include "Game.h"

GameObjectManager::GameObjectManager()
{
}

/**
This little bit may take a bit to wrap your head around.  std::for_each is a handy little method that takes two iterators,
one representing where to start, the other representing where to stop and finally it takes a unary function 
(meaning it takes a single parameter) that is to be called on each iteration.
*/
GameObjectManager::~GameObjectManager()
{
	std::for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
}

void GameObjectManager::add(std::string name, VisibleGameObject *gameObject) {
	_gameObjects.insert(std::pair<std::string, VisibleGameObject*> (name, gameObject));
}

void GameObjectManager::remove(std::string name)
{
	std::map<std::string, VisibleGameObject*>::iterator results = _gameObjects.find(name);
	if (results != _gameObjects.end())
	{
		delete results->second;
		_gameObjects.erase(results);
	}
}

VisibleGameObject* GameObjectManager::get(std::string name) const
{
	std::map<std::string, VisibleGameObject*>::const_iterator result = _gameObjects.find(name);

	if (result == _gameObjects.end())
		return NULL;
	
	return result->second;
}

int GameObjectManager::getObjectCount() const
{	
	return _gameObjects.size();
}

void GameObjectManager::drawAll(sf::RenderWindow &renderWindow)
{
	std::map<std::string, VisibleGameObject*>::const_iterator i = _gameObjects.begin();

	while (i != _gameObjects.end())
	{
		i->second->draw(renderWindow);
		i++;
	}
}

void GameObjectManager::updateAll()
{
	std::map<std::string, VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
	sf::Clock clock;
	float timeDelta = clock.getElapsedTime().asSeconds() * 10000.0f;
	clock.restart();
	//sf::Time timeDelta;

	while (itr != _gameObjects.end())
	{
		itr->second->update(timeDelta);
		itr++;
	}
}