#pragma once
#include <string>
#include <iostream> 
#include <SFML/Graphics.hpp>
#include "map.h"


class Player
{
private:
	float x, y;
public:
	float  w, h, dx, dy, speed = 0; //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
	int dir = 0; //направление (direction) движения игрока
	sf::String File; //файл с расширением
	sf::Image image;//сфмл изображение
	sf::Texture texture;//сфмл текстура
	sf::Sprite sprite;//сфмл спрайт
	Player(sf::String F, float X, float Y, float W, float H);
	void update(float);
	void interactionWithMap();
	float getplayercoordinateX();
	float getplayercoordinateY();
	~Player();
};
