#include <SFML\Graphics.hpp>
#include <SFML\System\Time.hpp>
#include "Bird.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1200, 600), "SFML works!");
	Bird bird;
	sf::Texture herotexture;//создаем объект Texture (текстура)
	herotexture.loadFromFile("images/pftcc.png");//загружаем картинку

	sf::Sprite herosprite;//создаем объект Sprite(спрайт)
	herosprite.setTexture(herotexture);//передаём в него объект Texture (текстуры)
	herosprite.setTextureRect(sf::IntRect(0, 0, 73.4, 67));//получили нужный нам прямоугольник с котом
	herosprite.setPosition(50, 25);//задаем начальные координаты появления спрайта
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