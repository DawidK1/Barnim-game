#include "enemy.h"
#include "util.h"
#include "gameStatusProvider.h"
#include "objectSpawner.h"
Barnim::Enemy::Enemy()
{
    hp = 100;
    maxHp=hp;
    armor = 25;
    attackRange = 80;
    attackPower = 25;
}
void Barnim::Enemy::attackHeroIfPossible()
{
    if (isAttackReady())
    {
        auto Heroes = getGameStatusProviderInstance()->getHeroes();
        for (auto hero : Heroes)
        {
            if (isInAttackRange(hero.get()))
            {
                hero->receiveDamage(attackPower);
                timesincelastattack = 0;
            }
        }
    }
}
void Barnim::Enemy::update(float timeElapsed)
{
    Barnim::Character::update(timeElapsed);
    goToTarget(getHeroPos());
    attackHeroIfPossible();
}

void Barnim::Enemy::goToTarget(glm::vec2 targetPositon)
{
    float length = glm::length(targetPositon - position);
    if (length < 40.0)
    {
        velocity = velocity * (float)0;
    }
    else
    {
        velocity = glm::normalize(targetPositon - position);
        velocity = velocity * (float)15.0;
    }
}

glm::vec2 Barnim::Enemy::getHeroPos()
{
    auto statusProvider = getGameStatusProviderInstance();

    auto heroes = statusProvider->getHeroes();

    if (heroes.size() > 0)
    {
        return heroes.at(0)->getPos();
    }
    return glm::vec2(5, 5);
}

void Barnim::Enemy::SpawnNewEnemy(glm::vec2 pos)
{
    auto spawner = Barnim::ObjectSpawner::getObjectSpawnerInstance();
    std::shared_ptr<Barnim::Enemy> enemyPtr(new Enemy());

    enemyPtr->LoadTexture("res/graphics/enemy.png", 200, 200, 0, 0);
    enemyPtr->position = pos;

    spawner->spawn(enemyPtr);
}