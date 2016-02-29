#include "stdafx.h"
#include "VisibleGameObject.h"

//Initialisierungsliste benutzen soll wohl besser sein als Zuweisung im Konstruktor
VisibleGameObject::VisibleGameObject():_isLoaded(false)
{
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

void VisibleGameObject::update(float elapsedTime)
{
}

//Position des Sprites �ndern
void VisibleGameObject::setPosition(float x, float y)
{
	if (_isLoaded)
	{
		_sprite.setPosition(x, y);
	}
}

sf::Vector2f VisibleGameObject::getPosition() const
{
	if (_isLoaded)
	{
		return _sprite.getPosition();
	}
	return sf::Vector2f();
}

sf::Sprite& VisibleGameObject::getSprite()
{
	return _sprite;
}

bool VisibleGameObject::isLoaded() const
{
	return _isLoaded;
}