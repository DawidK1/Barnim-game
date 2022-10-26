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

vector<shared_ptr<Barnim::Hero>> Barnim::GameStatusProvider::getHeroes()
{
    // TODO check controlPtr for NULL value;
    vector<shared_ptr<Barnim::Hero>> heroes;
    auto allObjects = controlPtr->getAllObjects();

    for (auto object : allObjects)
    {
        if (strcmp(typeid(*object).name(), typeid(Barnim::Hero).name()) == 0)
        {
            heroes.push_back(std::dynamic_pointer_cast<Barnim::Hero>(object));
        }
    }
    return heroes;
}

/*****************************************************/

Barnim::GameStatusProvider *getGameStatusProviderInstance()
{
    return &g_gameStatusProvider;
}