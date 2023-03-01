#ifndef HPBAR_H
#define HPBAR_H
#include "drawableObject.h"
#include <string>
#include <memory>
namespace Barnim
{
	class hpBar : public virtual DrawableObject
	{
	private:
		sf::Uint8 *pixels;
		int height;
		int width;
		enum colorType{
			COLOR_TYPE_RED=0,
			COLOR_TYPE_BLACK=1,
			COLOR_TYPE_TRANSPARENT=2
		};
		void paint();
		void paintpixel(int x, int y, enum colorType color);
		float fillLevel; //1.0 - full Bar, 0.0 - empty Bar
	public:
		hpBar();
		~hpBar();
		sf::Drawable &getTexture() override;
		void update(float timeElapsed) override;
		void setLevel(float level);
	};
};
#endif