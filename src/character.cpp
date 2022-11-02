#include "character.h"
void Barnim::Character::doDamage(int damage)
{
    hp=hp-(damage-armor);
    if (hp<=0)
    {
        remove();
    }
    
}