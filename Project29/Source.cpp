#include <SFML\Graphics.hpp>
#include <SFML\System\Time.hpp>
#include "Player.h"
#include <iostream>

int main() {
	float CurrentFrame = 0;//������ ������� ����
	sf::RenderWindow window(sf::VideoMode(1200, 600), "SFML works!");
	sf::Clock clock;
	Player p("pftcc.png", 250, 250, 75.6, 67);//������� ������ p ������ player,������ "hero.png" ��� ��� �����+����������, ����� ���������� �,�, ������, ������.
	//sf::Image image;
	//image.loadFromFile("images/pftcc.png");
	//image.createMaskFromColor(sf::Color(255, 255, 255));

	//sf::Texture herotexture;//������� ������ Texture (��������)
	//herotexture.loadFromImage(image);//��������� ��������
	//sf::Sprite herosprite;//������� ������ Sprite(������)
	//herosprite.setTexture(herotexture);//������� � ���� ������ Texture (��������)
	//herosprite.setTextureRect(sf::IntRect(0, 0, 75.6, 67));//�������� ������ ��� ������������� � �����
	p.sprite.setPosition(250, 200);//������ ��������� ���������� ��������� �������
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 500;
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
					//p.dir = 1; p.speed = 11;
					p.sprite.move(0, -11*time);
					//herosprite.move(0, -11 * time); //���������� ���� �������� ��������� �����
					//herosprite.move(0, -10);
					/*herosprite.setTextureRect(sf::IntRect(0, 0, 73.4, 67));*/
					CurrentFrame += 2.01*time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
					if (CurrentFrame > 14)
					{
						CurrentFrame -= 14;
					} // ���� ������ � �������� ����� - ������������ �����.
					p.sprite.setTextureRect(sf::IntRect(75.6* int(CurrentFrame), 0, 75.6, 67));
					//herosprite.setTextureRect(sf::IntRect(75.6* int(CurrentFrame), 0, 75.6, 67));
					//���������� �� ����������� �. ���������� �������� ��������� � ���������� � ������ 0,96,96*2, � ����� 0


				}

			}
		}
		p.sprite.move(0, 0.01);
		window.clear(sf::Color::Black);
		//p.update(time);
		window.draw(p.sprite);
		window.display();
	}
	return 0;
}