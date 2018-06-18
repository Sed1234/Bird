#include <SFML\Graphics.hpp>
#include <SFML\System\Time.hpp>
#include "Player.h"
#include <iostream>
#include "map.h"

int main() {
	sf::Image map_image;//объект изображени€ дл€ карты
	map_image.loadFromFile("images/map.png");//загружаем файл дл€ карты
	sf::Texture map;//текстура карты
	map.loadFromImage(map_image);//зар€жаем текстуру картинкой
	sf::Sprite s_map;//создаЄм спрайт дл€ карты
	s_map.setTexture(map);//заливаем текстуру спрайтом
	float CurrentFrame = 0;//хранит текущий кадр
	sf::RenderWindow window(sf::VideoMode(1200, 600), "SFML works!");
	sf::Clock clock;
	Player p("pftcc.png", 250, 250, 75.6, 67);//создаем объект p класса player,задаем "hero.png" как им€ файла+расширение, далее координата ’,”, ширина, высота.
	//sf::Image image;
	//image.loadFromFile("images/pftcc.png");
	//image.createMaskFromColor(sf::Color(255, 255, 255));

	//sf::Texture herotexture;//создаем объект Texture (текстура)
	//herotexture.loadFromImage(image);//загружаем картинку
	//sf::Sprite herosprite;//создаем объект Sprite(спрайт)
	//herosprite.setTexture(herotexture);//передаЄм в него объект Texture (текстуры)
	//herosprite.setTextureRect(sf::IntRect(0, 0, 75.6, 67));//получили нужный нам пр€моугольник с котом
	p.sprite.setPosition(250, 200);//задаем начальные координаты по€влени€ спрайта
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
					//herosprite.move(0, -11 * time); //происходит само движение персонажа влево
					//herosprite.move(0, -10);
					/*herosprite.setTextureRect(sf::IntRect(0, 0, 73.4, 67));*/
					CurrentFrame += 2.01*time; //служит дл€ прохождени€ по "кадрам". переменна€ доходит до трех суммиру€ произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
					if (CurrentFrame > 14)
					{
						CurrentFrame -= 14;
					} // если пришли к третьему кадру - откидываемс€ назад.
					p.sprite.setTextureRect(sf::IntRect(75.6* int(CurrentFrame), 0, 75.6, 67));
					//herosprite.setTextureRect(sf::IntRect(75.6* int(CurrentFrame), 0, 75.6, 67));
					//проходимс€ по координатам ’. получаетс€ начинаем рисование с координаты ’ равной 0,96,96*2, и оп€ть 0


				}

			}
		}
		p.sprite.move(0, 0.05);
		window.clear(sf::Color::Black);
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(sf::IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
				if (TileMap[i][j] == 's')  s_map.setTextureRect(sf::IntRect(32, 0, 32, 32));//если встретили символ s, то рисуем 2й квадратик
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(sf::IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик


				s_map.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превраща€ в карту. то есть задает каждому из них позицию. если убрать, то вс€ карта нарисуетс€ в одном квадрате 32*32 и мы увидим один квадрат

				window.draw(s_map);//рисуем квадратики на экран
			}
		//p.update(time);
		window.draw(p.sprite);
		window.display();
	}
	return 0;
}