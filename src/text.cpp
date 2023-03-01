#include "text.h"
#include <string>
#include "objectSpawner.h"
Barnim::Text::Text(std::string textToShow)
{
    font.loadFromFile("res/fonts/arial.ttf");
	text.setString(textToShow);
	text.setFont(font);
	text.setCharacterSize(45);
	text.setFillColor(sf::Color::White);
	//text.setPosition(250,250);
	position[0]=250;
	position[1]=250;
}
Barnim::Text::~Text(){}
sf::Drawable& Barnim::Text::getTexture()
{
    return text;
}
void Barnim::Text::update(float timeElapsed)
{
	Barnim::DrawableObject::update(timeElapsed);
	text.setPosition(sf::Vector2f(position[0], position[1]));
}
std::shared_ptr<Barnim::Text> Barnim::Text::getTextInTheMiddle(std::string textToShow)
{
	//auto spawner = Barnim::ObjectSpawner::getObjectSpawnerInstance();
    std::shared_ptr<Barnim::Text> textPtr(new Text(textToShow));

    textPtr->position[0] = 300;
    textPtr->position[1] = 250;
	textPtr->text.setPosition(sf::Vector2f(textPtr->position[0], textPtr->position[1]));
    //spawner->spawn(textPtr);
	return textPtr;
}