#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System\Time.hpp>
#include "Player.h"
#include <iostream>
#include "map.h"

int main() {
	sf::Image map_image;//������ ����������� ��� �����
	map_image.loadFromFile("images/map.png");//��������� ���� ��� �����
	sf::Texture map;//�������� �����
	map.loadFromImage(map_image);//�������� �������� ���������
	sf::Sprite s_map;//������ ������ ��� �����
	s_map.setTexture(map);//�������� �������� ��������
	float CurrentFrame = 0;//������ ������� ����
	sf::RenderWindow window(sf::VideoMode(1200, 600), "SFML works!");
	sf::Clock clock;
	Player p("pftcc.png", 250, 250, 75.6, 67);//������� ������ p ������ player,������ "hero.png" ��� ��� �����+����������, ����� ���������� �,�, ������, ������.
	p.sprite.setPosition(250, 200);//������ ��������� ���������� ��������� �������
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
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					p.dir = 1; p.speed = 0.01;
					p.sprite.move(0, -11*time);
					CurrentFrame += 2.01*time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
					if (CurrentFrame > 14)
					{
						CurrentFrame -= 14;
					}
					p.sprite.setTextureRect(sf::IntRect(75.6* int(CurrentFrame), 0, 75.6, 67));
				}
				p.update(time);
			}

		}
		
		p.sprite.move(0, 0.05);
		
		window.clear(sf::Color::Black);
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(sf::IntRect(0, 0, 32, 32)); //���� ��������� ������ ������, �� ������ 1� ���������
				if (TileMap[i][j] == '0') s_map.setTextureRect(sf::IntRect(64, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������
				s_map.setPosition(j * 32, i * 32);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������
				window.draw(s_map);//������ ���������� �� �����
			}
		
	
			for (int i = 1; i < HEIGHT_MAP - 1; i++)
				for (int j = 18; j < WIDTH_MAP; j++)
				{
					if ((i*j) % 12 == 7 || (i*j) % 11 == 3)
					{
						TileMap[i][j] = 's';
						s_map.setTextureRect(sf::IntRect(32, 0, 32, 32));
						s_map.move(0, 10 * time);
					}
					else
					{
						s_map.setTextureRect(sf::IntRect(0, 0, 32, 32));
						//s_map.move(10 * time, -10);
					}
						s_map.setPosition(j * 32, i * 32);
						window.draw(s_map);
					//������ ���������� �� �����		
				}		
		
		window.draw(p.sprite);
		window.display();
	}
	return 0;
}