#ifndef TEXT_H
#define TEXT_H
#include "drawableObject.h"
#include <string>
#include <memory>
namespace Barnim
{
	class Text : public virtual DrawableObject
	{
	private:
		sf::Font font;
		sf::Text text;

	public:
		Text(std::string textToShow);
		~Text();
		sf::Drawable &getTexture() override;
		void update(float timeElapsed)override;
		std::shared_ptr<Barnim::Text> static getTextInTheMiddle(std::string textToShow);
	};
};
#endif