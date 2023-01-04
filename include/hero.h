#ifndef HERO_H
#define HERO_H
#include "character.h"
namespace Barnim
{
	class Hero : public virtual Character
	{
		private:
		volatile float timesincelastkeepress;
		double speed=50;
		public:
		Hero();
		~Hero(){};
		void onUpMovement();
		void onLeftMovement();
		void onRightMovement();
		void onDownMovement();
		void onAttack();
		void update(float timeElapsed)override;
	};
};
#endif