#include "hero.h"

void Barnim::Hero::onUpMovement()
{
    Barnim::DrawableObject::movement(UP);
}
void Barnim::Hero::onLeftMovement()
{
    Barnim::DrawableObject::movement(LEFT);
}
void Barnim::Hero::onRightMovement()
{
    Barnim::DrawableObject::movement(RIGHT);
}
void Barnim::Hero::onDownMovement()
{
    Barnim::DrawableObject::movement(DOWN);
}