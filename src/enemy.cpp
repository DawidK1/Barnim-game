#include "enemy.h"
#include "util.h"
#include "gameStatusProvider.h"

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

glm::vec2 Barnim::Enemy::getHeroPos()
{
    auto statusProvider = getGameStatusProviderInstance();

    auto heroes = statusProvider->getHeroes();

    if(heroes.size() > 0)
    {
        return heroes.at(0)->getPos();
    }
    return glm::vec2(5,5);
}