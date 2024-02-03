#ifndef FIRST_SCENE_H
#define FIRST_SCENE_H

#include "juniorit/GameCraft/Scene.h"

typedef struct FirstScene
{
    Scene base;
    void (*onUpdate)(struct FirstScene *thiz, int ticks);
} FirstScene;

FirstScene *new_first_scene();

#endif // FIRST_SCENE_H