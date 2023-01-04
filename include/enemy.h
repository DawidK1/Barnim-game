#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"
namespace Barnim
{
	class Enemy : public virtual Character
	{
		public:
		Enemy();
		~Enemy(){};
		void update(float timeElapsed)override;
		void goToTarget(glm::vec2 targetPositon);
		static void SpawnNewEnemy(glm::vec2 pos);
		void attackHeroIfPossible();
		private:
		glm::vec2 getHeroPos();
	};
};
#endif