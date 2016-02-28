#include "stdafx.h"
#include "Game.h"

//Start Methode. Sollte nur einmal im gesamten Programm aufgerufen werden.
void Game::Start()
{
	//Deswegen hier Überprüfung ob das Spiel noch nicht initialisiert worden ist
	if (_gameState != Uninitialized)
		return;

	//Spiel in 800x600 Auflösung und 32 bit Farbmodus starten, Titel: Looten und Leveln
	_mainWindow.create(sf::VideoMode(800, 600, 32), "Looten und Leveln!");
	_gameState = Game::ShowingSplash;

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

void Game::showSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

void Game::showMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.show(_mainWindow);

	switch (result)
	{
	case MainMenu::Exit:
		_gameState = Game::Exiting;
		break;
	case MainMenu::Play:
		_gameState = Game::Playing;
		break;
	}
}

void Game::GameLoop()
{
	sf::Event currentEvent;
	while (_mainWindow.pollEvent(currentEvent))
	{
		switch (_gameState)
		{
			case Game::ShowingMenu:
			{
				showMenu();
				break;
			}
			case Game::ShowingSplash:
			{
				showSplashScreen();
				break;
			}
			case Game::Playing:
			{
				_mainWindow.clear(sf::Color(150,250,100));
				_mainWindow.display();

				if (currentEvent.type == sf::Event::Closed)
				{
					_gameState = Game::Exiting;
				}
				break;
			}
		}
	}
}

//Die beiden Membervariablen von Game hier initialisieren, da sie static sind und wir keinen Konstruktor haben
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;