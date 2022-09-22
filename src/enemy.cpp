#include "enemy.h"
#include "util.h"
void Barnim::Enemy::update(float timeElapsed)
{
    Barnim::DrawableObject::update(timeElapsed);
    goToTarget(glm::vec2 (400,100));
}
void Barnim::Enemy::goToTarget(glm::vec2 targetPositon)
{
    float length=glm::length(targetPositon-position);
    if (length<0.001)
    {
        velocity=velocity*(float)0;
    }
    else
    {
        velocity=glm::normalize(targetPositon-position);
        velocity=velocity*(float)15.0;
    }
}