#include "hero.h"

void Barnim::Hero::onUpMovement()
{
    velocity[1]=-speed;
    timesincelastkeepress=0;
}
void Barnim::Hero::onLeftMovement()
{
    velocity[0]=-speed;
    timesincelastkeepress=0;
}
void Barnim::Hero::onRightMovement()
{
    velocity[0]=+speed;
    timesincelastkeepress=0;
}
void Barnim::Hero::onDownMovement()
{
    velocity[1]=+speed;
    timesincelastkeepress=0;
}
void Barnim::Hero::update(float timeElapsed)
{
    Barnim::DrawableObject::update(timeElapsed);
    timesincelastkeepress+=timeElapsed;
    if (timesincelastkeepress>0.4)
    {
        velocity[0]=0;
        velocity[1]=0;
    }
}