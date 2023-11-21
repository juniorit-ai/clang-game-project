#include "FirstScene.h"
#include "juniorit/GameCraft/Game.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>

// The static keyword indicates that the variable will be initialized by the compiler and it can only be accessed within this file.
static Sprite *sprite = NULL;

// The update event of the scene; this is where all the game animation and logic occur.
// 'ticks' is the time elapsed per frame, in milliseconds.
void first_scene_on_update(FirstScene *thiz, int ticks)
{
    // Since FirstScene is a derived object, we need to call the parent's event 'scene_on_update' to ensure proper functionality.
    // Casting 'thiz' from 'FirstScene*' to 'Scene*' changes the pointer type to the parent type.
    scene_on_update((Scene *)thiz, ticks);

    // The static keyword here ensures that 'timeLapse' is initialized by the compiler only once.
    // As a result, 'timeLapse' will not be reset to 0 on subsequent calls to this function.
    static int timeLapse = 0;

    timeLapse += ticks; // This is equivalent to timeLapse = timeLapse + ticks.

    // Mathematical calculation for oscillation. The logic here might be complex, 
    // but we can ask AI to generate the code easily, ignore the logic if you don't understand for now
    // it oscillates the scale between 1 and 1.01.
    float frequency = M_PI / 1000;
    float scale = 1 + 0.01 * sin(timeLapse * frequency);

    // Update the sprite's scale periodically to create a heartbeat-like effect.
    sprite->setScale(sprite, scale);
}


// handle the keyboard event of the scene, you can ingore the code for now
void first_scene_on_keyboard(FirstScene *thiz, Event event, int keyCode)
{
    scene_on_keyboard((Scene *)thiz, event, keyCode);

}

// handle he mouse event of the scene, you can ingore the code for now
void first_scene_on_mouse(FirstScene *thiz, Event event, Point point)
{
    scene_on_mouse((Scene *)thiz, event, point);

}

// Initialize the first scene by adding a sprite/image to it.
void first_scene_init(FirstScene *thiz)
{
    // Ensure that the pointer to the FirstScene instance is not NULL. Or assert() will force the application exit.
    assert(thiz != NULL);

    // Cast the FirstScene instance to a Scene pointer.
    // This is done because FirstScene is a child 'class' of Scene, 
    // and we need to operate on it as a Scene.
    Scene *scene = (Scene *)thiz;

    // Create a new sprite from an image file. 
    // This function returns a pointer to the created sprite.
    sprite = new_sprite("t-rex.png");

    // Add the created sprite as a child to the scene.
    // This step integrates the sprite into the scene so it can be rendered and managed.
    scene->add_child(scene, sprite);

    // Set the sprite's top-left coordinate.
    sprite->setPosition(sprite, 100, 200);
}

// destroy the FirstScene object, you can ingore the code for now
void first_scene_destroy(FirstScene *thiz)
{
    scene_destroy((Scene *)thiz);
}

// create the FirstScene object, you can ingore the code for now
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