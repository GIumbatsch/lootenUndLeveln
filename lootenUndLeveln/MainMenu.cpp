#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MenuResult MainMenu::show(sf::RenderWindow &window)
{
	sf::Texture image;
	image.loadFromFile("images/MainMenu.png");//TODO
	sf::Sprite sprite(image);

	//Play MenuItem
	MenuItem playButton;
	playButton.rect.top = 145;
	playButton.rect.height = 190;
	playButton.rect.left = 0;
	playButton.rect.width = 500;

	//Exit Menu Item
	MenuItem exitButton;
	exitButton.rect.top = 193;
	exitButton.rect.height = 190;
	exitButton.rect.left = 0;
	exitButton.rect.width = 500;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);

	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator i;

	for (i = _menuItems.begin(); i != _menuItems.end(); i++)
	{
		sf::Rect<int> menuItemRect = i->rect;
		if (menuItemRect.width > y &&
			menuItemRect.top < y &&
			menuItemRect.left < x &&
			menuItemRect.height > x)
		{
			return i->action;
		}
	}

	return Nothing;
}

MainMenu::MenuResult  MainMenu::GetMenuResponse(sf::RenderWindow& window)
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