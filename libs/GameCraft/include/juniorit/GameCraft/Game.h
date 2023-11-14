#ifndef JUNIORIT_GAMECRAFT_GAME_H
#define JUNIORIT_GAMECRAFT_GAME_H

#include "juniorit/GameCraft/Scene.h" // Assuming Scene is defined in scene.h

#define GAME_FPS 60

typedef struct SceneNode{
    Scene* scene;
    struct SceneNode* next;
} SceneNode;

typedef struct Game{
    void *window;
    void *renderer;
    int width;
    int height;
    SceneNode* scenes;        // Head of the linked list of scenes
    Scene* currentScene;      // Pointer to the current active scene

    // Member function pointers
    void (*init)(struct Game* thiz, int width, int height);
    void (*add_scene)(struct Game* thiz, Scene* scene);
    void (*remove_scene)(struct Game* thiz, Scene* scene);
    void (*set_current_scene)(struct Game* thiz, Scene* scene);
    void (*onKeyboard)(struct Game* thiz, Event event, int keyCode);
    void (*onMouse)(struct Game* thiz, Event event, Point point);
    void (*run)(struct Game* thiz); // the main game loop
    void (*destroy)(struct Game* thiz);
} Game;

// Function declarations
Game* game_instance();
void game_on_update();
void game_destroy(Game *thiz);

#endif // JUNIORIT_GAMECRAFT_GAME_H
