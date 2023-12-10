#include "juniorit/GameCraft/Sprite.h"
#include "juniorit/GameCraft/Game.h"
#include "juniorit/GameCraft/utils.h"

#include <stdlib.h>
#include <assert.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void sprite_set_Position(Sprite *thiz, float top, float left)
{
    thiz->top = top;
    thiz->left = left;

    thiz->reDraw = true;
}

void sprite_set_Scale(Sprite *thiz, float scale)
{
    thiz->scale = scale;

    thiz->reDraw = true;
}

void sprite_set_angle(Sprite *thiz, float angle)
{
    thiz->angle = angle;

    thiz->reDraw = true;
}

void sprite_set_flip(Sprite *thiz, FlipMode mode)
{
    thiz->flip = mode;

    thiz->reDraw = true;
}

void sprite_set_center(Sprite *thiz, Point point)
{
    thiz->center = point;

    thiz->reDraw = true;
}

void sprite_set_frame(Sprite *thiz, int frameIndex)
{
    thiz->frameIndex = frameIndex;

    thiz->reDraw = true;
}

// Function to update the sprite
void sprite_on_update(Sprite *thiz, int ticks)
{
  
}

void sprite_on_keyboard(Sprite *thiz, Event event, int keyCode)
{
  
}

void sprite_on_mouse(Sprite *thiz, Event event, Point point)
{
  
}

static SDL_RendererFlip getSDLFlip(FlipMode flip) {
    SDL_RendererFlip sdlFlip;
    switch (flip)
    {
    case FLIP_NONE:
        sdlFlip = SDL_FLIP_NONE;
        break;
    case FLIP_HORIZONTAL:
        sdlFlip = SDL_FLIP_HORIZONTAL;
        break;
    case FLIP_VERTICAL:
        sdlFlip = SDL_FLIP_VERTICAL;
        break;
    case FLIP_DIAGONAL:
        sdlFlip = SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL;
        break;
    
    default:
        sdlFlip = SDL_FLIP_NONE;
        break;
    }

    return sdlFlip;
}

// Function to draw the sprite
void sprite_on_draw(Sprite *thiz)
{
    Game* game = game_instance();

    if(thiz->frames == NULL) {
        const Rect dst = { thiz->left, thiz->top, thiz->width * thiz->scale, thiz->height * thiz->scale};
        SDL_RenderCopyEx((SDL_Renderer*) game->renderer, (SDL_Texture*)thiz->texture, NULL, (const SDL_Rect *)&dst, thiz->angle, (SDL_Point*)&thiz->center, getSDLFlip(thiz->flip));
    } else {
        const Rect src = thiz->frames[thiz->frameIndex];
        const Rect dst = { thiz->left, thiz->top, src.w * thiz->scale, src.h * thiz->scale};
        SDL_RenderCopyEx((SDL_Renderer*) game->renderer, (SDL_Texture*)thiz->texture, (const SDL_Rect *)&src, (const SDL_Rect *)&dst, thiz->angle, (SDL_Point*)&thiz->center, getSDLFlip(thiz->flip));
    }

    thiz->reDraw = false;
}

// Destructor function for Sprite
void sprite_destroy(Sprite *thiz)
{
    if (thiz->texture != NULL)
    {
        SDL_DestroyTexture(thiz->texture);
    }

    if(thiz->frames != NULL) {
        free(thiz->frames);
    }

    free(thiz);
}

void sprite_init(Sprite *thiz, const char *image, Rect* frames, int frameSize)
{
    assert(thiz != NULL);
    
    thiz->onUpdate = sprite_on_update;
    thiz->onDraw = sprite_on_draw;
    thiz->onKeyboard = sprite_on_keyboard;
    thiz->onMouse = sprite_on_mouse;

    thiz->setFrame = sprite_set_frame;
    thiz->setPosition = sprite_set_Position;
    thiz->setScale = sprite_set_Scale;
    thiz->setAngle = sprite_set_angle;
    thiz->setCenter = sprite_set_center;
    thiz->setFlip = sprite_set_flip;

    thiz->destroy = sprite_destroy;

    char imagePath[128];
    getResourceFilePath(imagePath, sizeof(imagePath), image);

    SDL_Surface *surface = IMG_Load(imagePath);
    assert(surface != NULL);

    Game *game = game_instance();

    thiz->left = 0.0;
    thiz->top = 0.0;
    thiz->scale = 1.0;
    thiz->angle = 0.0;

    Point center = {0};
    thiz->center = center;

    thiz->flip = FLIP_NONE;


    thiz->width = surface->w;
    thiz->height = surface->h;

    thiz->frames = frames;
    thiz->frameSize = frameSize;
    thiz->frameIndex = 0;


    thiz->texture = (void *)SDL_CreateTextureFromSurface((SDL_Renderer *)game->renderer, surface);
    assert(thiz->texture != NULL);

    SDL_FreeSurface(surface);

    thiz->reDraw = true;
}


// Constructor function for Sprite
Sprite *new_sprite(const char *image)
{
    Sprite *thiz = malloc(sizeof(Sprite));
    assert(thiz != NULL);
    sprite_init(thiz, image, NULL, 1);

    return thiz;
}

Sprite *new_spriteSheet(const char *image, Rect* frames, int frameSize)
{
    Sprite *thiz = malloc(sizeof(Sprite));
    assert(thiz != NULL);
    sprite_init(thiz, image, frames, frameSize);

    return thiz;
}