#include "gameStatusModifier.h"
#include <typeinfo>
#include <iostream>
#include <cstring>
#include "enemy.h"
extern Barnim::GameStatusModifier g_gameStatusModifier;

using namespace std;

void Barnim::GameStatusModifier::attachGameControl(Control *control)
{
    controlPtr = control;
}

Barnim::GameStatusModifier *getGameStatusModifierInstance()
{
    return &g_gameStatusModifier;
}
void Barnim::GameStatusModifier::pauseGame()
{
    controlPtr ->pauseGame();
}
void Barnim::GameStatusModifier::resumeGame()
{
    controlPtr ->resumeGame();
}