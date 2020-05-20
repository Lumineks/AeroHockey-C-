#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class GameMap
{
private:
	Image mapImage;
	Texture mapTexture;
	Sprite mapSprite;

public:
	GameMap(std::string file);

	Sprite GetSprite();

	void SetTextureRect(int startX, int startY, int x, int y);
	void SetPosition(int x, int y);
};

