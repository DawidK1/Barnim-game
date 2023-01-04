#include "character.h"
Barnim::Character::Character()
{
    hp = 100;
    armor = 20;
    attackRange = 50;
    attackPower = 100;
};
void Barnim::Character::doDamage(int damage)
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
    return true;
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