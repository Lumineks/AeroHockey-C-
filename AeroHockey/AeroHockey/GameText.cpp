#include "GameText.h"

GameText::GameText(std::string fontName, int characterSize, Color color)
{
	this->font.loadFromFile(fontName);
	this->characterSize = characterSize;
	this->text.setFont(this->font);
	this->text.setCharacterSize(this->characterSize);
	this->text.setFillColor(color);
	this->text.setStyle(Text::Bold);
	this->text.setString("");
}

Text GameText::GetText() { return text; }

Text GameText::Display(std::string text, int x, int y)
{
	this->text.setString(text);
	this->text.setPosition(x, y);

	return this->text;
}
