#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "GameObjectManager.h"

class Game
{
public:
	static void Start();
	static sf::RenderWindow& GetWindow();
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

private:
	static bool isExiting();
	static void GameLoop(sf::Clock &clock);

	static void showSplashScreen();
	static void showMenu();

	//Die verschiedenen Statuse in denen sich das Spiel befinden kann
	enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting };

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;

	static GameObjectManager _gameObjectManager;
};