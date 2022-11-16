#ifndef CHARACTER_H
#define CHARACTER_H
#include "drawableObject.h"
namespace Barnim
{
	class Character : public virtual DrawableObject
	{
		public:
		Character(){hp=100;armor=20;attackRange=50;attackPower=100;};
		~Character(){};
		void doDamage(int damage);
		bool isAttackReady();
		bool isInAttackRange(Barnim::Character* characterToAttack);
		protected:
		int hp;
		int armor;
		int attackPower;
		int attackRange;
		float attackSpeed;
		float lastAttackTime;
	};
};
#endif