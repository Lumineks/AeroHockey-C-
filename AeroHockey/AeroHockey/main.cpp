#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Player.h"
#include "GameMap.h"
#include "GameText.h"

using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(1024, 476), "Air Hockey", Style::Close);
	
	GameText text("Typesauce.ttf", 30, Color(224, 255, 254));//color);

	GameMap map("map.png");	

	Player player("hero.png", 250, 250, 100.0, 100.0);

	Clock clock;

	double dX = 0;
	double dY = 0;

	while (window.isOpen())
	{
		double time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800;

		Vector2i pixelPos = Mouse::getPosition(window);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed)
				if (event.key.code == Mouse::Left)
					if (player.GetSprite().getGlobalBounds().contains(pixelPos.x, pixelPos.y))
					{
						std::cout << "isClicked!\n";
						dX = (double)pixelPos.x - (double)player.GetSprite().getPosition().x;
						dY = (double)pixelPos.y - (double)player.GetSprite().getPosition().y;
						player.isMove = true;		
					}

			if (event.type == Event::MouseButtonReleased)
				if (event.key.code == Mouse::Left)
					player.isMove = false; 
		}

		if(player.isMove)
		{
			player.SetPosition(pixelPos.x - dX, pixelPos.y - dY);
		}

		window.clear();

		std::ostringstream playerScoreString;
		playerScoreString << player.GetPlayerScore();

		window.draw(text.Display("SCORE - " + playerScoreString.str(), 460, 50));

		player.Update(time);

		window.draw(player.GetSprite());

		map.SetTextureRect(20, 384, 470, 20);
		map.SetPosition(42, 0);
		window.draw(map.GetSprite());

		map.SetTextureRect(20, 158, 470, 20);
		map.SetPosition(512, 0);
		window.draw(map.GetSprite());

		map.SetTextureRect(439, 459, 455, 559);
		map.SetPosition(40, 15);
		window.draw(map.GetSprite());
		

		map.SetTextureRect(439, 459, 455, 559);
		map.SetPosition(40, 366);
		window.draw(map.GetSprite());

		map.SetTextureRect(20, 271, 470, 20);
		map.SetPosition(42, 455);
		window.draw(map.GetSprite());
		
		map.SetTextureRect(20, 48, 470, 20);
		map.SetPosition(512, 457);
		window.draw(map.GetSprite());

		window.display();
	}

	return 0;
}