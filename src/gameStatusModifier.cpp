#include "gameStatusModifier.h"
#include <typeinfo>
#include <iostream>
#include <cstring>
#include "enemy.h"
#include "objectSpawner.h"
extern Barnim::GameStatusModifier g_gameStatusModifier;

using namespace std;

Barnim::GameStatusModifier::GameStatusModifier() 
{
    controlPtr = NULL; 
    pauseText=Barnim::Text::getTextInTheMiddle("Pause");
};
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
    Barnim::ObjectSpawner::getObjectSpawnerInstance()->spawn(pauseText);
}
void Barnim::GameStatusModifier::resumeGame()
{
    controlPtr ->resumeGame();
    Barnim::ObjectSpawner::getObjectSpawnerInstance()->despawn(pauseText.get());
}
void Barnim::GameStatusModifier::togglePause()
{
    if (controlPtr->isGamePaused)
    {
        resumeGame();
    }
    else
    {
        pauseGame();
    }
}