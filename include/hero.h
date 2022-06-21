#ifndef HERO_H
#define HERO_H
#include "DrawableObject.h"
namespace Barnim
{
	class Hero : public virtual DrawableObject
	{
		public:
		sf::Texture getTexture() { return texture; };
	};
};
#endif