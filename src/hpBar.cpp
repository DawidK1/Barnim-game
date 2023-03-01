#include "hpBar.h"
#include <string>
#include "objectSpawner.h"
Barnim::hpBar::hpBar()
{
	height = 10;
	width = 50;
	fillLevel = 1.0;
	pixels = new sf::Uint8[(width * height * 4)];
	texture.create(width, height);
	texture.setSmooth(true);
	size = glm::vec2(width, height);
	sprite.setPosition(sf::Vector2f(position[0], position[1]));
	sprite.setTexture(texture);
	paint();
}
Barnim::hpBar::~hpBar() {}
sf::Drawable &Barnim::hpBar::getTexture()
{
	return sprite;
}
void Barnim::hpBar::update(float timeElapsed)
{
	paint();
	Barnim::DrawableObject::update(timeElapsed);
}
void Barnim::hpBar::paint()
{
	int fillLevelPixel = width * fillLevel;
	for (int i = 0; i < width; i++)
	{
		enum colorType color = (i < fillLevelPixel) ? COLOR_TYPE_RED : COLOR_TYPE_TRANSPARENT;
		for (int j = 0; j < height; j++)
		{
			paintpixel(i, j, color);
		}
	}
	texture.update(pixels);
}
void Barnim::hpBar::paintpixel(int x, int y, enum colorType color)
{
	int pixelIndex = (((x * 1) + (y * width)) * 4);
	switch (color)
	{
	case COLOR_TYPE_RED:
		pixels[pixelIndex] = 255;
		pixels[pixelIndex + 1] = 0;
		pixels[pixelIndex + 2] = 0;
		pixels[pixelIndex + 3] = 200;
		break;
	case COLOR_TYPE_BLACK:
		pixels[pixelIndex] = 0;
		pixels[pixelIndex + 1] = 0;
		pixels[pixelIndex + 2] = 0;
		pixels[pixelIndex + 3] = 200;
		break;
	case COLOR_TYPE_TRANSPARENT:
		pixels[pixelIndex + 3] = 0;
		break;
	}
}
void Barnim::hpBar::setLevel(float level)
{
    if (level>=0.0 && level<=1.0)
    {
        fillLevel=level;   
    }
}