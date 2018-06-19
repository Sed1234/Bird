#include "Bird.h"

Bird::Bird()
{
	isJumping = false;
	sign = '*';
	body.push_back(sf::RectangleShape(sf::Vector2f(50, 50)));
	body.push_back(sf::RectangleShape(sf::Vector2f(50, 50)));
	body.push_back(sf::RectangleShape(sf::Vector2f(50, 50)));
	float cnt = 250;
	for (auto & point : body)
	{
		point.setPosition(cnt, 250);
		cnt += 50;
		point.setFillColor(sf::Color::Cyan);
	}
}


Bird::~Bird()
{
}

//void Bird::draw()
//{
//	for (Pixel pixel : body) {
//		pixel.draw(sign);
//	}
//}

void Bird::jump(const float & y)
{
	for (auto & point : body) 
	{
		point.setPosition(point.getPosition() + sf::Vector2f(0, y));
	}
}

void Bird::fall()
{
	for (auto & point : body)
	{
		point.setPosition(point.getPosition() + sf::Vector2f(0, 0.01));
	}
}

//void Dino::settle()
//{
//	for (Pixel & pixel : body) {
//		pixel.y++;
//	}
//}

