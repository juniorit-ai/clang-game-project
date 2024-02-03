#include "FirstScene.h"
#include "juniorit/GameCraft/Game.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>

static Sprite *sprite = NULL;

void first_scene_on_update(FirstScene *thiz, int ticks)
{
    scene_on_update((Scene *)thiz, ticks);

    static int timeLapse = 0;
    timeLapse += ticks;

    double frequency = M_PI / 1000;
    double scale = 1 + 0.01 * sin(timeLapse * frequency);

    sprite->setScale(sprite, scale);
}

void first_scene_on_keyboard(FirstScene *thiz, Event event, int keyCode)
{
    scene_on_keyboard((Scene *)thiz, event, keyCode);
}

void first_scene_on_mouse(FirstScene *thiz, Event event, Point point)
{
    scene_on_mouse((Scene *)thiz, event, point);
}

void first_scene_init(FirstScene *thiz)
{
    assert(thiz != NULL);

    Scene *scene = (Scene *)thiz;

    sprite = new_sprite("t-rex.png");
    scene->add_child(scene, sprite);

    sprite->setPosition(sprite, 100, 200);
}

void first_scene_destroy(FirstScene *thiz)
{
    scene_destroy((Scene *)thiz);
}

FirstScene *new_first_scene()
{
    FirstScene *thiz = malloc(sizeof(FirstScene));
    assert(thiz != NULL);

    Scene *base = (Scene *)thiz;
    scene_init(base);

    base->destroy = (void (*)(Scene *))first_scene_destroy;
    base->onUpdate = (void (*)(Scene *, int))first_scene_on_update;
    base->onKeyboard = (void (*)(Scene *, Event, int))first_scene_on_keyboard;
    base->onMouse = (void (*)(Scene *, Event, Point))first_scene_on_mouse;

    first_scene_init(thiz);

    return thiz;
}