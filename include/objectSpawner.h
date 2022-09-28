#ifndef OBJECTSPAWNER_H
#define OBJECTSPAWNER_H
#include "DrawableObject.h"
#include "Control.h"
namespace Barnim
{
    class ObjectSpawner
    {
    private:
        Control *controlPtr;
    public:
        void attachGameControl(Control *control);
        Barnim::ObjectSpawner *objectSpawnerInstance();
    };
};
#endif