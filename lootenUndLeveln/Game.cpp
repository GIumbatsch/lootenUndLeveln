#include "stdafx.h"
#include "Game.h"
#include "PlayerSprite.h"

//Start Methode. Sollte nur einmal im gesamten Programm aufgerufen werden.
void Game::Start()
{
	//Deswegen hier �berpr�fung ob das Spiel noch nicht initialisiert worden ist
	if (_gameState != Uninitialized)
		return;

	//Spiel in 800x600 Aufl�sung und 32 bit Farbmodus starten, Titel: Looten und Leveln
	_mainWindow.create(sf::VideoMode(800, 600, 32), "Looten und Leveln!");

	// FramerateLimit
	_mainWindow.setFramerateLimit(60);


	//Spieler laden
	PlayerSprite *player = new PlayerSprite();
	player->setPosition(370, 300);

	_gameObjectManager.add("Spieler", player);

	//Spielzustand auf "Splashscreen laden" setzen
	_gameState = Game::ShowingSplash;

	//Solange das Spiel nicht beendet wird l�uft der Game Loop weiter
	sf::Clock *clock = new sf::Clock();


	while (!isExiting()) {
		GameLoop(*clock);
	}

	//Wenn das Spiel beendet wird schlie�t sich das Fenster
	_mainWindow.close();
}

//Gibt an ob das Spiel geschlossen wird oder nicht
bool Game::isExiting() {
	//Spiel wird geschlossen wenn der Status auf Beenden gesetzt wird
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

sf::RenderWindow& Game::GetWindow()
{
	return _mainWindow;
}

//Funktion zum Anzeigen des Splashscreens
void Game::showSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

//Funktion zum Aufrufen des Men�s
void Game::showMenu()
{
	MainMenu mainMenu;

	//result ist der Men� Punkt der angeklickt wird
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


/**
Der Game Loop l�uft die ganze Zeit durch und �ndert die Zust�nde in denen sich das Spiel befindet,
je nachdem was f�r eine Aktion ausgef�hrt wird bzw. je nachdem was f�r Events eintreten.
*/
void Game::GameLoop(sf::Clock &clock)
{
	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);

	if (clock.getElapsedTime().asMilliseconds() > 10) {
		sf::Time time = clock.restart();
		float timeDelta = time.asMilliseconds();
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
			_mainWindow.clear(sf::Color(0, 0, 0));

			_gameObjectManager.updateAll(timeDelta);
			_gameObjectManager.drawAll(_mainWindow);

			_mainWindow.display();

			if (currentEvent.type == sf::Event::Closed)
			{
				_gameState = Game::Exiting;
			}

			if (currentEvent.type == sf::Event::KeyPressed)
			{
				if (currentEvent.key.code == sf::Keyboard::Escape) showMenu();
			}
			break;
		}
		}
	}
}

//Die beiden Membervariablen von Game hier initialisieren, da sie static sind und wir keinen Konstruktor haben
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;