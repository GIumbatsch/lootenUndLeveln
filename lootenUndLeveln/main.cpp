#include <SFML/Graphics.hpp>
#include <iostream>

bool moveRight = true;

void moveShape(sf::Shape &s, sf::RenderWindow &window)
{
	std::cout << "WindowX = " << window.getSize().x << "| xPos = " << s.getPosition().x << std::endl;
	if (moveRight && s.getPosition().x > window.getSize().x)
	{
		moveRight = false;
	}
	else if(!moveRight && s.getPosition().x < 0)
	{
		moveRight = true;
	}
	if (moveRight)
	{
		s.move(1.0f, 0.0f);
	}
	else
	{
		s.move(-1.0f, 0.0f);
	}

}



int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 720), "SFML works!");
	
	sf::CircleShape shape1(100.f);
	shape1.setFillColor(sf::Color::White);

	sf::Vector2f size(200.f,200.f);
	sf::RectangleShape shape2(size);
	shape2.setFillColor(sf::Color::Green);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		moveShape(shape1, window);

		window.clear();
		window.draw(shape1);
		window.draw(shape2);
		window.display();
	}

	return 0;
}