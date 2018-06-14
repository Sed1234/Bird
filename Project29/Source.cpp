#include <SFML\Graphics.hpp>
#include <SFML\System\Time.hpp>
#include "Bird.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1200, 600), "SFML works!");
	Bird bird;
	sf::Texture herotexture;//������� ������ Texture (��������)
	herotexture.loadFromFile("images/pftcc.png");//��������� ��������

	sf::Sprite herosprite;//������� ������ Sprite(������)
	herosprite.setTexture(herotexture);//������� � ���� ������ Texture (��������)
	herosprite.setTextureRect(sf::IntRect(0, 0, 73.4, 67));//�������� ������ ��� ������������� � �����
	herosprite.setPosition(50, 25);//������ ��������� ���������� ��������� �������
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				float dy = 0;
 				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					dy = -50;
				}
				bird.jump(dy);
			}
		}
		bird.fall();
		window.clear();
		window.draw(herosprite);
		/*for (auto & point : bird.body)
		{
			window.draw(point);
		}*/
		window.display();
	}
	return 0;
}