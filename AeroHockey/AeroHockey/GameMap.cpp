#include "GameMap.h"

GameMap::GameMap(std::string file)
{
	mapImage.loadFromFile("images/" + file);
	mapTexture.loadFromImage(mapImage);
	mapSprite.setTexture(mapTexture);
}

Sprite GameMap::GetSprite() { return mapSprite; }

void GameMap::SetTextureRect(int startX, int startY, int x, int y)
{
	mapSprite.setTextureRect(IntRect(startX, startY, x, y));
}

void GameMap::SetPosition(int x, int y)
{
	mapSprite.setPosition(x, y);
}
