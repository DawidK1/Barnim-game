#include "gameStatusProvider.h"
#include <typeinfo>
#include <iostream>
#include <cstring>
extern Barnim::GameStatusProvider g_gameStatusProvider;

using namespace std;

void Barnim::GameStatusProvider::attachGameControl(Control *control)
{
    controlPtr = control;
}

vector<Barnim::Hero *> Barnim::GameStatusProvider::getHeroes()
{
    // TODO check controlPtr for NULL value;
    vector<Barnim::Hero *> heroes;
    auto allObjects = controlPtr->getAllObjects();

    for (DrawableObject *object : allObjects)
    {
        if (strcmp(typeid(*object).name(), typeid(Barnim::Hero).name()) == 0)
        {
            heroes.push_back(dynamic_cast<Barnim::Hero *>(object));
        }
    }
    return heroes;
}

/*****************************************************/

Barnim::GameStatusProvider *getGameStatusProviderInstance()
{
    return &g_gameStatusProvider;
}