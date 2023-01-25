#include "text.h"
#include <string>

Barnim::Text::Text(string textToShow)
{
    font.loadFromFile("res/fonts/arial.ttf");
	text.setString(textToShow);
	text.setFont(font);
	text.setCharacterSize(45);
	text.setFillColor(sf::Color::White);
	text.setPosition(250,250);
}
Barnim::Text::~Text(){}
sf::Drawable& Barnim::Text::getTexture()
{
    return text;
}