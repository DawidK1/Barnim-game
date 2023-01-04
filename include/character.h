#ifndef CHARACTER_H
#define CHARACTER_H
#include "drawableObject.h"
namespace Barnim
{
	class Character : public virtual DrawableObject
	{
		public:
		Character();
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