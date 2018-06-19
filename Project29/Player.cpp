#include "Player.h"



Player::Player(sf::String F, float X, float Y, float W, float H)
{
	dx = 0; dy = 0; speed = 0; dir = 0;
	File = F;//��� �����+����������
	w = W; h = H;//������ � ������
	image.loadFromFile("images/" + File);//���������� � image ���� ����������� ������ File �� ��������� ��, ��� �������� ��� �������� �������. � ����� ������ "hero.png" � ��������� ������ ���������� 	image.loadFromFile("images/hero/png");
	image.createMaskFromColor(sf::Color(255, 255, 255));
	texture.loadFromImage(image);//���������� ���� ����������� � ��������
	sprite.setTexture(texture);//�������� ������ ���������
	x = X; y = Y;//���������� ��������� �������
	sprite.setTextureRect(sf::IntRect(0, 0, w, h));
}

void Player::update(float time)
{
	
	switch (dir)//��������� ��������� � ����������� �� �����������. (������ ����� ������������� �����������)
	{
	case 1: dy = -10; dx = speed;   
		     break;
	//case 2: dx = 0; dy = speed;   break;
	}

	x += dx*time;//�� �������� �� �������� �����. ���� ��������� �� ����� �������� �������� ��������� � ��� ��������� ��������
	y += dy;//���������� �� ������
	speed = 0;//�������� ��������, ����� �������� �����������.
	sprite.setPosition(x, y); //������� ������ � ������� x y , ����������. ���������� ������� � ���� �������, ����� �� ��� ������ ����� �� �����.
	interactionWithMap();
}
void Player::interactionWithMap()
{
	for (int i = y / 32; i < (y + h) / 32; i++)//���������� �� ��������, �������������� � �������,, �� ���� �� ���� ����������� ������� 32*32, ������� �� ���������� � 9 �����. ��� ������� ������� ����.
		for (int j = x / 32; j<(x + w) / 32; j++)//��� ����� �� 32, ��� ����� �������� ����� ���������, � ������� �������� �������������. (�� ���� ������ ������� 32*32, ������� ����� ������������ ������ �� ���������� ���������). � j<(x + w) / 32 - ������� ����������� ��������� �� ����. �� ���� ���������� ������ ������� ��������, ������� ������������� � ����������. ����� ������� ���� � ����� ����� ������� �� ����, ������� �� �� ������ �������� (���������������� � ������), �� ������� �������� (���������������� � ������)
		{
			if (TileMap[i][j] == '0')//���� ��� ��������� ������������� ������� 0 (�����), �� ��������� "����������� ��������" ���������:
			{
				if (dy>0)//���� �� ��� ����,
				{
					y = j * 2;//�� �������� ���������� ����� ���������. ������� �������� ���������� ������ ���������� �� �����(�����) � ����� �������� �� ������ ������� ���������.
				}
				if (dy<0)
				{
					y = j * 2;//���������� � ������� �����. dy<0, ������ �� ���� ����� (���������� ���������� ������)
				}
			}
			if (TileMap[i][j] == 's')
			{ //���� ������ ����� 's' (������)
				//x = 300; y = 300;//����� �� ��������... �������� ������������ �����
				TileMap[i][j] = ' ';//������� ������, ���� ����� �����. ����� � �� �������, ������.
			}
		}
}
 float Player::getplayercoordinateX() {
	return x;
}
 float Player::getplayercoordinateY() {
	return y;
}

Player::~Player()
{
}
