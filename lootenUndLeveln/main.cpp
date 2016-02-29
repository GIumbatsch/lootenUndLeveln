#include <SFML/Graphics.hpp>
#include <iostream>

bool moveRight = true;
sf::Time elapsed;

void moveShape(sf::Shape &s, sf::RenderWindow &window, float speed)
{
	std::cout << "WindowX = " << window.getSize().x << "| xPos = " << s.getPosition().x << std::endl;
	if (moveRight && s.getPosition().x > window.getSize().x)
	{
		moveRight = false;
	}
	else if (!moveRight && s.getPosition().x < 0)
	{
		moveRight = true;
	}
	if (moveRight)
	{
		s.move(1.0f*speed*elapsed.asMilliseconds() , 0.0f);
	}
	else
	{
		s.move(-1.0f*speed*elapsed.asMilliseconds(), 0.0f);
	}
}

void movePlayer(sf::Shape &player) {

	sf::Vector2f movement(0.f,0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		movement.x -= 1.f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		movement.x += 1.f;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		movement.y -= 1.f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		movement.y += 1.f;
	}

	movement.x *= elapsed.asMilliseconds();
	movement.y *= elapsed.asMilliseconds();

	player.move(movement);
}



int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 720), "SFML works!");
	window.setFramerateLimit(60);

	sf::CircleShape shape1(100.f);
	shape1.setFillColor(sf::Color::White);

	sf::Vector2f size(200.f, 200.f);
	sf::RectangleShape shape2(size);
	shape2.move(0.f, 200.0f);
	shape2.setFillColor(sf::Color::Green);

	sf::RectangleShape shape3(size);
	shape3.move(window.getSize().x - shape3.getSize().x,200.f);
	shape3.setFillColor(sf::Color::Yellow);


	sf::RectangleShape player(size*0.5f);
	player.move(window.getSize().x / 2.f, window.getSize().y - 200.f);
	player.setOutlineColor(sf::Color::Blue);
	player.setOutlineThickness(5.f);

	// Time
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		elapsed = clock.restart();

		moveShape(shape1, window, 1.f);
		moveShape(shape2, window, 0.5f);
		moveShape(shape3,window, -0.5f);
		movePlayer(player);

		window.clear();
		window.draw(shape1);
		window.draw(shape2);
		window.draw(shape3);
		window.draw(player);
		window.display();
	}

	return 0;
}