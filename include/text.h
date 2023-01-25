#ifndef TEXT_H
#define TEXT_H
#include "drawableObject.h"
#include <string>
namespace Barnim
{
	class Text : public virtual DrawableObject
	{
	private:
		sf::Font font;
		sf::Text text;

	public:
		Text(string textToShow);
		~Text();
		sf::Drawable &getTexture() override;
	};
};
#endif