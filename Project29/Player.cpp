#include "Player.h"



Player::Player(sf::String F, float X, float Y, float W, float H)
{
	File = F;//имя файла+расширение
	w = W; h = H;//высота и ширина
	image.loadFromFile("images/" + File);//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта. В нашем случае "hero.png" и получится запись идентичная 	image.loadFromFile("images/hero/png");
	image.createMaskFromColor(sf::Color(255, 255, 255));//убираем ненужный темно-синий цвет, эта тень мне показалась не красивой.
	texture.loadFromImage(image);//закидываем наше изображение в текстуру
	sprite.setTexture(texture);//заливаем спрайт текстурой
	x = X; y = Y;//координата появления спрайта
	sprite.setTextureRect(sf::IntRect(0, 0, w, h));
}

void Player::update(float)
{
	sf::Clock clock;
	float time = clock.getElapsedTime().asMicroseconds();
	switch (dir)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
	{
	case 1: dx = 0; dy = speed;   break;//по иксу задаем отрицательную скорость, по игреку зануляем. получается, что персонаж идет только влево
	case 2: dx = 0; dy = speed;   break;
	}

	x += dx*time;//то движение из прошлого урока. наше ускорение на время получаем смещение координат и как следствие движение
	y += dy*time;//аналогично по игреку

	speed = 0;//зануляем скорость, чтобы персонаж остановился.
	sprite.setPosition(x, y); //выводим спрайт в позицию x y , посередине. бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте.
}


Player::~Player()
{
}
