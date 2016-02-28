#include "stdafx.h"
#include "SplashScreen.h"

void SplashScreen::show(sf::RenderWindow &renderWindow)
{
	//Falls das Bild nicht existiert
	sf::Texture image;
	if (image.loadFromFile("Ressourcendateien/images/SplashScreen.png") != true)
	{
		//wird es einfach nicht geladen
		return;
	}

	sf::Sprite sprite(image);

	//Ansonsten anzeigen
	renderWindow.draw(sprite);
	renderWindow.display();

	sf::Event event;

	while(true)
	{
		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::KeyPressed ||
				event.type == sf::Event::EventType::MouseButtonPressed ||
				event.type == sf::Event::EventType::Closed)
			{
				return;
			}
		}
	}
}