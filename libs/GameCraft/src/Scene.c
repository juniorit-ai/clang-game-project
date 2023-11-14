#include "juniorit/GameCraft/Scene.h"
#include "juniorit/GameCraft/Game.h"
#include <stdlib.h>
#include <assert.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


// Add child sprite to the scene
void scene_add_child(Scene *thiz, Sprite *sprite)
{
    SpriteNode *new_node = (SpriteNode *)malloc(sizeof(SpriteNode));
    assert(new_node != NULL);

    new_node->sprite = sprite;
    new_node->next = NULL;

    // If the list is empty, add the new node as the first node
    if (thiz->children == NULL)
    {
        thiz->children = new_node;
    }
    else
    {
        // Find the last node in the list
        SpriteNode *current = thiz->children;
        while (current->next != NULL)
        {
            current = current->next;
        }
        // Add the new node at the end of the list
        current->next = new_node;
    }
}

// Remove child sprite from the scene
void scene_remove_child(Scene *thiz, Sprite *sprite)
{
    SpriteNode *current = thiz->children;
    while (current != NULL)
    {
        SpriteNode* entry = current;
        if (entry->sprite == sprite)
        {
            current = entry->next;
            entry->sprite->destroy(entry->sprite);
            free(entry);
            return;
        }
        current = entry->next;
    }
}

// Update the scene (and its children)
void scene_on_update(Scene *thiz, int ticks)
{
    SpriteNode *current = thiz->children;
    while (current != NULL)
    {
        current->sprite->onUpdate(current->sprite, ticks);
        if(current->sprite->reDraw) {
            thiz->reDraw = true;
        }
        current = current->next;
    }
}

// Draw the scene (and its children)
void scene_on_draw(Scene *thiz)
{
    if(!thiz->reDraw) {
        return;
    }

    Game* game = game_instance();

    SDL_RenderClear((SDL_Renderer*) game->renderer); 

    SpriteNode *current = thiz->children;
    while (current != NULL)
    {
        current->sprite->onDraw(current->sprite);
        current = current->next;
    }

    SDL_RenderPresent((SDL_Renderer*) game->renderer);

    thiz->reDraw = false;
}

// Destructor function for Scene
void scene_destroy(Scene *thiz)
{
    SpriteNode *current = thiz->children;
    while (current != NULL)
    {
        SpriteNode *next = current->next;
        current->sprite->destroy(current->sprite);

        free(current);
        current = next;
    }
    free(thiz);
}

void scene_on_keyboard(Scene *thiz, Event event, int keyCode)
{
    SpriteNode *current = thiz->children;
    while (current != NULL)
    {
        current->sprite->onKeyboard(current->sprite, event, keyCode);
        current = current->next;
    }

}

void scene_on_mouse(Scene *thiz, Event event, Point point)
{
    SpriteNode *current = thiz->children;
    while (current != NULL)
    {
        current->sprite->onMouse(current->sprite, event, point);
        current = current->next;
    }
}

void scene_init(Scene *thiz)
{
    assert(thiz != NULL);

    thiz->reDraw = false;
    thiz->children = NULL;
    thiz->add_child = scene_add_child;
    thiz->remove_child = scene_remove_child;

    thiz->onUpdate = scene_on_update;
    thiz->onDraw = scene_on_draw;
    thiz->onKeyboard = scene_on_keyboard;
    thiz->onMouse = scene_on_mouse;

    thiz->destroy = scene_destroy;
}

// Constructor function for Scene
Scene *new_scene()
{
    Scene *thiz = malloc(sizeof(Scene));
    assert(thiz != NULL);
    
    scene_init(thiz);

    return thiz;
}

