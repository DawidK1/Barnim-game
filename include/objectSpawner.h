#ifndef OBJECTSPAWNER_H
#define OBJECTSPAWNER_H

#include "Control.h"
namespace Barnim
{
    class ObjectSpawner
    {
    public:
        Control *controlPtr;
    public:
        void attachGameControl(Control *control);
        static Barnim::ObjectSpawner *getObjectSpawnerInstance();

    };
};
#endif