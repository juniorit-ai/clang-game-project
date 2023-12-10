#include "FirstScene.h"
#include "juniorit/GameCraft/Game.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>

static Sprite *sprite = NULL;
static Sprite *background = NULL;

// The update event of the scene; this is where all the game animation and logic occur.
// 'ticks' is the time elapsed per frame, in milliseconds.
void first_scene_on_update(FirstScene *thiz, int ticks)
{
   
    scene_on_update((Scene *)thiz, ticks);

    static int timeLapse = 0;

    timeLapse += ticks; 

    float frequency = M_PI / 500;
    float angle = 3 * sin(timeLapse * frequency);

    sprite->setAngle(sprite, angle);

    // Move the sprite from left to right, then flip and move from right to left in the range of the screen (width 1280)
    float spriteWidth = sprite->width * sprite->scale;
    float spriteLeft = sprite->left;
    float spriteRight = spriteLeft + spriteWidth;
    float screenRight = background->width;

    int speed = 2; 

    if (sprite->flip == FLIP_NONE)
    {
        // Move the sprite to the right
        spriteLeft += speed;
        spriteRight += speed;

        // Check if the sprite has reached the right end of the screen
        if (spriteRight >= screenRight)
        {
            // Flip the sprite horizontally
            sprite->setFlip(sprite, FLIP_HORIZONTAL);
        }
    }
    else if (sprite->flip == FLIP_HORIZONTAL)
    {
        // Move the sprite to the left
        spriteLeft -= speed;
        spriteRight -= speed;

        // Check if the sprite has reached the left end of the screen
        if (spriteLeft <= 0)
        {
            // Flip the sprite back to normal
            sprite->setFlip(sprite, FLIP_NONE);
        }
    }

    sprite->setPosition(sprite, sprite->top, spriteLeft);
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

    Scene *scene = (Scene *)thiz;

    // size - width: 1280, height 512
    background = new_sprite("background.png");
    scene->add_child(scene, background);

    // size - width: 342, height: 218
    sprite = new_sprite("t-rex.png");

    // Add the created sprite as a child to the scene.
    // This step integrates the sprite into the scene so it can be rendered and managed.
    scene->add_child(scene, sprite);

    Point point = {.x = sprite->width/2, .y = sprite->height/2};
    sprite->setCenter(sprite, point);

    // Set the sprite's top-left coordinate.
    sprite->setPosition(sprite, 250, 20);
    sprite->setFlip(sprite, FLIP_HORIZONTAL);
    
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