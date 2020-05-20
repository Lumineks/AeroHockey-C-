#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
private:
	double x;
	double y;
	double height;
	double width;
	double dx;
	double dy;
	double speed;
	int direction;
	int score;
	
	std::string file;
	Image image;
	Texture texture;
	Sprite sprite;

public:
	bool isMove;

	Player(std::string file, int x, int y, double w, double h);

	Sprite GetSprite();
	double GetX();
	double GetY();
	int GetPlayerScore();	

	void SetPosition(double x, double y);

	void Update(double time);
};

