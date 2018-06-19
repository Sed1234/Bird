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
	float  w, h, dx, dy, speed = 0; //���������� ������ � � �, ������ ������, ��������� (�� � � �� �), ���� ��������
	int dir = 0; //����������� (direction) �������� ������
	sf::String File; //���� � �����������
	sf::Image image;//���� �����������
	sf::Texture texture;//���� ��������
	sf::Sprite sprite;//���� ������
	Player(sf::String F, float X, float Y, float W, float H);
	void update(float);
	void interactionWithMap();
	float getplayercoordinateX();
	float getplayercoordinateY();
	~Player();
};
