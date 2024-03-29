#include "hero.h"
#include "gameStatusProvider.h"
#include "gameStatusModifier.h"
#include "text.h"
Barnim::Hero::Hero()
{
    hp = 200;
    maxHp=hp;
    armor = 15;
    attackRange = 100;
    attackPower = 75;
}
void Barnim::Hero::onUpMovement()
{
    velocity[1] = -speed;
    timesincelastkeepress = 0;
}
void Barnim::Hero::onLeftMovement()
{
    velocity[0] = -speed;
    timesincelastkeepress = 0;
}
void Barnim::Hero::onRightMovement()
{
    velocity[0] = speed;
    timesincelastkeepress = 0;
}
void Barnim::Hero::onDownMovement()
{
    velocity[1] = speed;
    timesincelastkeepress = 0;
}
void Barnim::Hero::update(float timeElapsed)
{
    Barnim::Character::update(timeElapsed);
    timesincelastkeepress += timeElapsed;
    if (timesincelastkeepress > 0.4)
    {
        velocity[0] = 0;
        velocity[1] = 0;
    }
}
void Barnim::Hero::onAttack()
{
    if (isAttackReady())
    {
        timesincelastattack = 0;
        auto Enemies = getGameStatusProviderInstance()->getEnemies();
        for (auto enemy : Enemies)
        {
            if (isInAttackRange(enemy.get()))
            {
                enemy->receiveDamage(attackPower);
            }
        }
    }
}
void Barnim::Hero::receiveDamage(int damage)
{
    if (armor < damage)
    {
        hp = hp - (damage - armor);
        if (hp <= 0)
        {
            //Barnim::Text::showTextInTheMiddle("You die");
            cout<<endl<<"You die";
            getGameStatusModifierInstance()->pauseGame();
        }
    }
}