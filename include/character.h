#ifndef CHARACTER_H
#define CHARACTER_H
#include "drawableObject.h"
#include "hpBar.h"
#include <memory>
#include "objectSpawner.h"
namespace Barnim
{
	class Character : public virtual DrawableObject
	{
	public:
		Character();
		~Character();
		virtual void receiveDamage(int damage);
		bool isAttackReady();
		bool isInAttackRange(Barnim::Character *characterToAttack);
		void update(float timeElapsed) override;

	protected:
		int hp;
		int maxHp;
		int armor;
		int attackPower;
		int attackRange;
		float attackSpeed;
		float lastAttackTime;
		float timesincelastattack;
		std::shared_ptr<Barnim::hpBar> hpBar;
	};
};
#endif