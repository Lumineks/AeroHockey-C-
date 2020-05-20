#include "Player.h"

Player::Player(std::string file, int x, int y, double w, double h)
{
	this->file = file;
	this->width = w;
	this->height = h;
	image.loadFromFile("images/" + this->file);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	this->x = x;
	this->y = y;
	sprite.setTextureRect(IntRect(13, 18, w, h));
	direction = 0;
	score = 0;
	speed = 0;
	isMove = false;
}

Sprite Player::GetSprite() { return sprite; }

double Player::GetX() { return x; }

double Player::GetY() { return y; }

int Player::GetPlayerScore() { return score; }

void Player::SetPosition(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Player::Update(double time)
{
	switch (direction)
	{
	case 0:
		dx = speed;
		dy = 0;
		break;
	case 1:
		dx = -speed;
		dy = 0;
		break;
	case 2:
		dx = 0;
		dy = speed;
		break;
	case 3:
		dx = 0;
		dy = -speed;
		break;
	}
	x += dx * time;
	y += dy * time;

	speed = 0;
	sprite.setPosition(x, y);
}
