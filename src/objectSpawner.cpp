#include "objectSpawner.h"

using namespace std;

extern Barnim::ObjectSpawner g_objectSpawner;
void Barnim::ObjectSpawner::attachGameControl(Control *control)
{
    controlPtr = control;
}

Barnim::ObjectSpawner * Barnim::ObjectSpawner::getObjectSpawnerInstance()
{
    return &g_objectSpawner;
}
void Barnim::ObjectSpawner::spawn(shared_ptr<Barnim::DrawableObject>object)
{
    controlPtr->addDrawableObject(object);
}
void Barnim::ObjectSpawner::despawn(Barnim::DrawableObject * objectToRemove)
{
    controlPtr->removeDrawableObject(objectToRemove);
}