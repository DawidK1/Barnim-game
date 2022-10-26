#ifndef HERO_H
#define HERO_H
#include "drawableObject.h"
namespace Barnim
{
	class Hero : public virtual DrawableObject
	{
		private:
		volatile float timesincelastkeepress;
		double speed=50;
		public:
		Hero(){};
		~Hero(){};
		void onUpMovement();
		void onLeftMovement();
		void onRightMovement();
		void onDownMovement();
		void update(float timeElapsed)override;
	};
};
#endif