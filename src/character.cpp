#include "character.h"
Barnim::Character::Character()
{
    hp = 100;
    armor = 20;
    attackRange = 50;
    attackPower = 100;
    attackSpeed = 5;
};
void Barnim::Character::receiveDamage(int damage)
{
    if (armor < damage)
    {
        hp = hp - (damage - armor);
        if (hp <= 0)
        {
            remove();
        }
    }
}
bool Barnim::Character::isAttackReady()
{
    if (timesincelastattack>attackSpeed)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Barnim::Character::isInAttackRange(Barnim::Character *characterToAttack)
{
    float distance = glm::length(characterToAttack->getPos() - getPos());
    if (distance < attackRange)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Barnim::Character::update(float timeElapsed)
{
    Barnim::DrawableObject::update(timeElapsed);
    timesincelastattack += timeElapsed;
}