#include "hero.h"

void Barnim::Hero::onUpMovement()
{
    Barnim::DrawableObject::movement(0);
}
void Barnim::Hero::onLeftMovement()
{
    Barnim::DrawableObject::movement(1);
}
void Barnim::Hero::onRightMovement()
{
    Barnim::DrawableObject::movement(2);
}
void Barnim::Hero::onDownMovement()
{
    Barnim::DrawableObject::movement(3);
}