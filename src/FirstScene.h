#ifndef FIRST_SCENE_H
#define FIRST_SCENE_H
#include "juniorit/GameCraft/Scene.h"

// Scene structure
typedef struct FirstScene{
    Scene base;
    void (*onUpdate)(struct FirstScene* thiz, int ticks);
} FirstScene;

// Function declarations
FirstScene* new_first_scene();

#endif // FIRST_SCENE_H