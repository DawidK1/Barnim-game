#ifndef ENEMY_H
#define ENEMY_H
#include "drawableObject.h"
namespace Barnim
{
	class Enemy : public virtual DrawableObject
	{
		public:
		Enemy(){hp=100;};
		~Enemy(){};
		void update(float timeElapsed)override;
		void goToTarget(glm::vec2 targetPositon);
		static void SpawnNewEnemy(glm::vec2 pos);
		void doDamage(int damage);
		private:
		glm::vec2 getHeroPos();
		int hp;
	};
};
#endif