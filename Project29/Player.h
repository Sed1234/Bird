#pragma once
#include <string>
#include <iostream> 
#include <SFML/Graphics.hpp>

class Player
{
public:
	float x, y, w, h, dx, dy, speed = 0; //���������� ������ � � �, ������ ������, ��������� (�� � � �� �), ���� ��������
	int dir = 0; //����������� (direction) �������� ������
	sf::String File; //���� � �����������
	sf::Image image;//���� �����������
	sf::Texture texture;//���� ��������
	sf::Sprite sprite;//���� ������
	Player(sf::String F, float X, float Y, float W, float H);
	void update(float); 
	~Player();
};

