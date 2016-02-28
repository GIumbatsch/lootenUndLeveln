#include "Game.h"

void Game::Start()
{
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Looten und Leveln!");
	_gameState = Game::Playing;

	while (!isExiting()) {
		GameLoop();
	}

	_mainWindow.close();
}

bool Game::isExiting() {
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

