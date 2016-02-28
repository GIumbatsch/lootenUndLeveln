#include "stdafx.h"
#include "GameObjectManager.h"

GameObjectManager::GameObjectManager()
{
}

//Bin noch nicht so richtig dahinter gekommen wie dieser Destruktor funktioniert, hab ihn aber trotzdem erstmal übernommen
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