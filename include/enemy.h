#ifndef ENEMY_H
#define ENEMY_H
#include "DrawableObject.h"
namespace Barnim
{
	class Enemy : public virtual DrawableObject
	{
		public:
		Enemy(){};
		~Enemy(){};
		void update(float timeElapsed)override;
		void goToTarget(glm::vec2 targetPositon);
	};
};
#endif