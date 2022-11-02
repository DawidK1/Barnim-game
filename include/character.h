#ifndef CHARACTER_H
#define CHARACTER_H
#include "drawableObject.h"
namespace Barnim
{
	class Character : public virtual DrawableObject
	{
		public:
		Character(){hp=100;armor=20;};
		~Character(){};
		void doDamage(int damage);
		protected:
		int hp;
		int armor;
	};
};
#endif