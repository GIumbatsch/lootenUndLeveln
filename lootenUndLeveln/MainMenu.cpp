#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MenuResult MainMenu::show(sf::RenderWindow &window)
{
	sf::Texture image;
	image.loadFromFile("images/MainMenu.png");
	sf::Sprite sprite(image);

	//Play Menü Item spezifizieren
	MenuItem playButton;
	playButton.rect.top = 145;
	playButton.rect.height = 190;
	playButton.rect.left = 0;
	playButton.rect.width = 500;
	playButton.action = Play;

	//Exit Menü Item spezifizieren
	MenuItem exitButton;
	exitButton.rect.top = 193;
	exitButton.rect.height = 380;
	exitButton.rect.left = 0;
	exitButton.rect.width = 500;
	exitButton.action = Exit;

	//In die Liste der Menü Items hinzufügen
	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);

	//und anzeigen
	window.draw(sprite);
	window.display();

	//Den Button der geklickt wurde als Response des Menüs zurückgeben
	return GetMenuResponse(window);
}

//Bei jedem Klick wird überprüft ob sich der Klick innerhalb eines der Buttons des Menüs befand
MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator i;

	for (i = _menuItems.begin(); i != _menuItems.end(); i++)
	{
		sf::Rect<int> menuItemRect = i->rect;
		if (menuItemRect.contains(sf::Vector2<int>(x, y)))
		{
			return i->action;
		}
	}

	return Nothing;
}

//quasi der "Menü Loop" funktionsweise analog zum Game Loop
MainMenu::MenuResult  MainMenu::GetMenuResponse(sf::RenderWindow &window)
{
	sf::Event menuEvent;

	while (true)
	{
		while (window.pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}
	}
}