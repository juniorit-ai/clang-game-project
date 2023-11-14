#include "juniorit/GameCraft/Game.h"
#include <stdlib.h>
#include <assert.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

static Game *instance = NULL;

// Function implementations for the Game struct
void game_init_window(Game *thiz, int width, int height);
void game_add_scene(Game *thiz, Scene *scene);
void game_remove_scene(Game *thiz, Scene *scene);
void game_set_current_scene(Game *thiz, Scene *scene);
void game_run(Game *thiz);
void game_init(Game *thiz, int width, int height);

void game_on_keyboard(Game *thiz, Event event, int keyCode);
void game_on_mouse(Game *thiz, Event event, Point point);

#ifndef __EMSCRIPTEN__
static bool running = true;
#endif

EMSCRIPTEN_KEEPALIVE
void triggerQuitEvent()
{
    SDL_Event event;
    event.type = SDL_QUIT;
    SDL_PushEvent(&event);
}

static Event eventMap(Uint32 eventType)
{
    switch (eventType) {
        case SDL_KEYDOWN:
            return KEYDOWN;
        case SDL_KEYUP:
            return KEYUP;
        case SDL_MOUSEBUTTONDOWN:
            return MOUSEBUTTONDOWN;
        case SDL_MOUSEBUTTONUP:
            return MOUSEBUTTONUP;
        case SDL_MOUSEMOTION:
            return MOUSEMOTION;
        default:
            return UNKNOWN;

    }
}

void processEvents()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {

        case SDL_KEYDOWN:
        case SDL_KEYUP:
        {
            int sdlKeyCode = e.key.keysym.sym;

            if (sdlKeyCode == SDLK_ESCAPE)
            {
                triggerQuitEvent();
                return;
            }
            game_on_keyboard(instance, eventMap(e.type), sdlKeyCode);
        }

            break;
        case SDL_WINDOWEVENT:
    
            break;
        case SDL_MOUSEWHEEL:
        {
            Point point = {e.wheel.x, e.wheel.y};
            game_on_mouse(instance, eventMap(e.type), point);
        }

            break;
        case SDL_MOUSEMOTION:
        case SDL_MOUSEBUTTONUP:
        case SDL_MOUSEBUTTONDOWN:
        {
            Point point = {e.motion.x, e.motion.y};
            game_on_mouse(instance, eventMap(e.type), point);
        }
            
            break;
        case SDL_QUIT:

#ifdef __EMSCRIPTEN__
            emscripten_cancel_main_loop();
#else
            running = false;
#endif
            break;
        default:
            break;
        }
    }
}

void game_on_keyboard(Game *thiz, Event event, int keyCode)
{
    if (instance != NULL && instance->currentScene != NULL)
    {
        instance->currentScene->onKeyboard(instance->currentScene, event, keyCode);
    }

}

void game_on_mouse(Game *thiz, Event event, Point point)
{
    if (instance != NULL && instance->currentScene != NULL)
    {
        instance->currentScene->onMouse(instance->currentScene, event, point);
    }
}

// Function to get the singleton game instance
Game *game_instance()
{
    if (instance == NULL)
    {
        instance = (Game *)malloc(sizeof(Game));
        if (instance != NULL)
        {
            // Assigning function pointers
            instance->init = game_init;
            instance->add_scene = game_add_scene;
            instance->remove_scene = game_remove_scene;
            instance->set_current_scene = game_set_current_scene;
            instance->run = game_run;
            instance->destroy = game_destroy;

            instance->onKeyboard = game_on_keyboard;
            instance->onMouse = game_on_mouse;

            // Initialize default values
            instance->window = NULL;
            instance->renderer = NULL;
            instance->width = 640;  // Default width
            instance->height = 480; // Default height
            instance->scenes = NULL;
            instance->currentScene = NULL;

            /*EM_ASM(
                var style = document.createElement('style');
                style.innerHTML = '#controls { display: none; }';
                document.head.appendChild(style);
            );*/
            
        }
    }
    return instance;
}

// Function to initialize the game instance

void game_init(Game *thiz, int width, int height)
{
    assert(thiz != NULL);
    
    //SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_VERBOSE);
    //SDL_Log("Start ...");

    int sdl_init_ret = SDL_Init(SDL_INIT_VIDEO);
    assert(sdl_init_ret == 0);

    thiz->width = width;
    thiz->height = height;

    thiz->window = (void *)SDL_CreateWindow("JuniorIT SDL2 Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, instance->width, instance->height, SDL_WINDOW_SHOWN);
    assert(thiz->window != NULL);

    thiz->renderer = (void *)SDL_CreateRenderer(thiz->window, -1, SDL_RENDERER_ACCELERATED);
    assert(thiz->renderer != NULL);
}

// Add a scene to the end of the game's scene list
void game_add_scene(Game *thiz, Scene *scene)
{
    assert(thiz != NULL);

    SceneNode *new_node = (SceneNode *)malloc(sizeof(SceneNode));
    assert(new_node != NULL);

    new_node->scene = scene;
    new_node->next = NULL;

    thiz->currentScene = scene;

    if (thiz->scenes == NULL)
    {
        // If the list is empty, add the new node as the first node
        thiz->scenes = new_node;
    }
    else
    {
        // Find the last node in the list
        SceneNode *current = thiz->scenes;
        while (current->next != NULL)
        {
            current = current->next;
        }
        // Add the new node at the end of the list
        current->next = new_node;
    }
}

// Remove a scene from the game
void game_remove_scene(Game *thiz, Scene *scene)
{
    if (thiz != NULL)
    {
        SceneNode *current = thiz->scenes;
        while (current != NULL)
        {
            SceneNode *entry = current;
            if (entry->scene == scene)
            {
                current = entry->next;
                entry->scene->destroy(entry->scene);
                free(entry);
                if (thiz->currentScene == scene)
                {
                    thiz->currentScene = NULL;
                }
                return;
            }
            current = entry->next;
        }
    }
}

// Update the game (and the current scene)
void game_on_update()
{
    int frameStart = SDL_GetTicks();
    int frameTicks = 1000 / GAME_FPS;

    if (instance != NULL && instance->currentScene != NULL)
    {
        processEvents();

        instance->currentScene->onUpdate(instance->currentScene, frameTicks);
        instance->currentScene->onDraw(instance->currentScene);
    }

    int frameTime = SDL_GetTicks() - frameStart;

    if (frameTicks > frameTime)
    {
        SDL_Delay(frameTicks - frameTime);
    }
}

void game_run(Game *thiz)
{

#ifdef __EMSCRIPTEN__
    // Set frame rate argument to 0 to use requestAnimationFrame
    emscripten_set_main_loop(game_on_update, 0, 1);
#else
    while (running)
    {
        game_on_update()
    }
#endif
}

void game_set_current_scene(Game *thiz, Scene *scene)
{
    if (thiz != NULL)
    {
        SceneNode *current = thiz->scenes;
        while (current != NULL)
        {
            if (current->scene == scene)
            {
                thiz->currentScene = scene;
                return;
            }
            current = current->next;
        }
        assert(NULL != "scene is not added to game yet!");
    }
}

// Function to destroy the game instance
void game_destroy(Game *thiz)
{
    assert(thiz == instance);
    if (thiz != NULL)
    {
        SceneNode *current = thiz->scenes;
        while (current != NULL)
        {
            SceneNode *next = current->next;
            current->scene->destroy (current->scene); // Assuming scene_destroy is defined
            free(current);
            current = next;
        }

        if (thiz->renderer != NULL)
        {

            SDL_DestroyRenderer((SDL_Renderer *)thiz->renderer);
            thiz->renderer = NULL;
        }

        if (thiz->window != NULL)
        {
            SDL_DestroyWindow((SDL_Window *)thiz->window);
            thiz->window = NULL;
        }

        SDL_Quit();

        SDL_Log("SDL_Quit");

        free(thiz);
        instance = NULL;
    }
}
