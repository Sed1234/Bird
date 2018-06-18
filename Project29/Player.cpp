#include "Player.h"



Player::Player(sf::String F, float X, float Y, float W, float H)
{
	File = F;//��� �����+����������
	w = W; h = H;//������ � ������
	image.loadFromFile("images/" + File);//���������� � image ���� ����������� ������ File �� ��������� ��, ��� �������� ��� �������� �������. � ����� ������ "hero.png" � ��������� ������ ���������� 	image.loadFromFile("images/hero/png");
	image.createMaskFromColor(sf::Color(255, 255, 255));//������� �������� �����-����� ����, ��� ���� ��� ���������� �� ��������.
	texture.loadFromImage(image);//���������� ���� ����������� � ��������
	sprite.setTexture(texture);//�������� ������ ���������
	x = X; y = Y;//���������� ��������� �������
	sprite.setTextureRect(sf::IntRect(0, 0, w, h));
}

void Player::update(float)
{
	sf::Clock clock;
	float time = clock.getElapsedTime().asMicroseconds();
	switch (dir)//��������� ��������� � ����������� �� �����������. (������ ����� ������������� �����������)
	{
	case 1: dx = 0; dy = speed;   break;//�� ���� ������ ������������� ��������, �� ������ ��������. ����������, ��� �������� ���� ������ �����
	case 2: dx = 0; dy = speed;   break;
	}

	x += dx*time;//�� �������� �� �������� �����. ���� ��������� �� ����� �������� �������� ��������� � ��� ��������� ��������
	y += dy*time;//���������� �� ������

	speed = 0;//�������� ��������, ����� �������� �����������.
	sprite.setPosition(x, y); //������� ������ � ������� x y , ����������. ���������� ������� � ���� �������, ����� �� ��� ������ ����� �� �����.
}


Player::~Player()
{
}
