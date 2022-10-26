#include "objectSpawner.h"

using namespace std;

extern Barnim::ObjectSpawner g_objectSpawner;
void Barnim::ObjectSpawner::attachGameControl(Control *control)
{
    controlPtr = control;
}

Barnim::ObjectSpawner *Barnim::ObjectSpawner::getObjectSpawnerInstance()
{
    return &g_objectSpawner;
}