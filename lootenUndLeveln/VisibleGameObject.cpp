#include "stdafx.h"
#include "VisibleGameObject.h"

VisibleGameObject::VisibleGameObject()
{
	_isLoaded == false;
}

VisibleGameObject::~VisibleGameObject()
{
}

//Laden des Objektes
void VisibleGameObject::load(std::string filename)
{
	//Falls keine Textur gefunden wird
	if (_image.loadFromFile(filename) == false)
	{
		_filename = "";
		//nicht laden lassen
		_isLoaded = false;
	}
	else
	{
		//ansonsten alle Member initialisieren
		_filename = filename;
		_sprite.setTexture(_image);
		_isLoaded = true;
	}
}

void VisibleGameObject::draw(sf::RenderWindow &window)
{
	//Wenn das Bild geladen wurde
	if (_isLoaded)
	{
		//zeichnen
		window.draw(_sprite);
	}
}

//Position des Sprites �ndern
void VisibleGameObject::setPosition(float x, float y)
{
	if (_isLoaded)
	{
		_sprite.setPosition(x, y);
	}
}