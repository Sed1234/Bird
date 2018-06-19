#pragma once
#include "Pixel.h"
#include <vector>
#include <SFML\Graphics.hpp>
class Bird
{
	char sign;
public:
	std::vector<sf::RectangleShape> body;
	bool isJumping;
	Bird();
	~Bird();
	//void draw();
	void jump(const float & y);
	void fall();
	//void settle();
};

