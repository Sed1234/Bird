#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System\Time.hpp>
#include "Player.h"
#include <iostream>
#include "map.h"
#include <vector>

int main() {
	sf::Image map_image;
	map_image.loadFromFile("images/map.png");
	sf::Texture map;
	map.loadFromImage(map_image);
	sf::Sprite s_map;
	s_map.setTexture(map);
	float CurrentFrame = 0;
	sf::RenderWindow window(sf::VideoMode(1200, 600), "SFML works!");
	sf::Clock clock;
	Player p("pftcc.png", 250, 250, 75.6, 67);
	p.sprite.setPosition(250, 200);
	std::vector<sf::Sprite> rocks;
	sf::Sprite rock;
	sf::Texture temp;
	temp.loadFromImage(map_image);
	for (size_t i = 0; i < 17; ++i) 
	 {
		rock.setTexture(temp);
		rock.setTextureRect(sf::IntRect(32, 0, 32, 32));
		rock.setPosition(sf::Vector2f((rand() % 18 + 18) * 32, (rand() % 18 - 2) * 32));
		rocks.push_back(rock);
	}
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		//std::cout << time << std::endl;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					p.dir = 1; p.speed = 0.05;
					p.sprite.move(0, -11 * time);
					CurrentFrame += 2.01*time;
					if (CurrentFrame > 14)
					{
						CurrentFrame -= 14;
					}
					p.sprite.setTextureRect(sf::IntRect(75.6* int(CurrentFrame), 0, 75.6, 67));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					p.dir = 2; p.speed = 0.05;
					//p.sprite.move(0, 0.05);
					p.sprite.move(0, -11 * time);
					CurrentFrame += 2.01*time;
					if (CurrentFrame > 14)
					{
						CurrentFrame -= 14;
					}
					p.sprite.setTextureRect(sf::IntRect(75.6* int(CurrentFrame), 0, 75.6, 67));
				}
			}
		}
		//p.sprite.move(0, 0.05);
		p.update(time,  window);
		window.clear(sf::Color::Black);
		for (int i = 0; i < HEIGHT_MAP; i++)
		{
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(sf::IntRect(0, 0, 32, 32));
				if (TileMap[i][j] == '0') s_map.setTextureRect(sf::IntRect(64, 0, 32, 32));
				if (TileMap[i][j] == '1') s_map.setTextureRect(sf::IntRect(96, 0, 32, 32));
				s_map.setPosition(j * 32, i * 32);
				window.draw(s_map);
			}
		}
		

		for (sf::Sprite & rock : rocks)
		{
			rock.setPosition(rock.getPosition() - sf::Vector2f(0.1, 0));
			if (p.sprite.getGlobalBounds().intersects(rock.getGlobalBounds()))
			{
				window.close();
			}
			window.draw(rock);
		}

		window.draw(p.sprite);
		window.display();
	}
	return 0;
}