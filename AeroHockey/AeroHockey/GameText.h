#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class GameText
{
private:
	Font font;
	Text text;
	int characterSize;

public:
	GameText(std::string fontName, int characterSize, Color color);

	Text GetText();

	Text Display(std::string text, int x, int y);
};

