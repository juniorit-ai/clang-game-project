#ifndef JUNIORIT_GAMECRAFT_SCENE_H
#define JUNIORIT_GAMECRAFT_SCENE_H
#include <stdbool.h>
#include "juniorit/GameCraft/Sprite.h" // Assuming Sprite is defined in sprite.h

// Node structure for the linked list of sprites
typedef struct SpriteNode {
    Sprite* sprite;
    struct SpriteNode* next;
} SpriteNode;

// Scene structure
typedef struct Scene {
    bool reDraw;
    SpriteNode* children;
    
    void (*add_child)(struct Scene* thiz, Sprite* sprite);
    void (*remove_child)(struct Scene* thiz, Sprite* sprite);
    void (*onUpdate)(struct Scene* thiz, int ticks);
    void (*onDraw)(struct Scene* thiz);
    void (*onKeyboard)(struct Scene* thiz, Event event, int keyCode);
    void (*onMouse)(struct Scene* thiz, Event event, Point point);
    void (*destroy)(struct Scene* thiz);
} Scene;

Scene* new_scene();
void scene_init(Scene *thiz);
void scene_on_update(Scene *thiz, int ticks);
void scene_on_keyboard(Scene *thiz, Event event, int keyCode);
void scene_on_mouse(Scene *thiz, Event event, Point point);
void scene_destroy(Scene *thiz);


#endif // JUNIORIT_GAMECRAFT_SCENE_H
