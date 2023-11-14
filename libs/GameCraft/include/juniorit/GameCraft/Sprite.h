#ifndef JUNIORIT_GAMECRAFT_SPRITE_H
#define JUNIORIT_GAMECRAFT_SPRITE_H
#include <stdbool.h>

typedef enum Event { KEYDOWN, KEYUP, MOUSEWHEEL, MOUSEBUTTONDOWN, MOUSEBUTTONUP, MOUSEMOTION, UNKNOWN } Event;

typedef enum FlipMode {
    FLIP_NONE = 0,
    FLIP_HORIZONTAL = 1,
    FLIP_VERTICAL = 2,
    FLIP_DIAGONAL = 3 // both horizontal and vertical
} FlipMode;

typedef struct Point
{
    int x; // The x coordinate of the point
    int y; // The y coordinate of the point
} Point;

typedef struct Rect {
    int x; // the x location of the rectangle's upper left corner
    int y; // the y location of the rectangle's upper top corner
    int w; // the width of the rectangle
    int h; // the height of the rectangle
} Rect;

// Sprite structure 
typedef struct Sprite {
    float top;
    float left;
    int width; // orignal image width
    int height; // orignal image height
    float scale;
    float angle;
    Point center;
    FlipMode flip;
    bool reDraw;
    void* texture;
    Rect* frames;
    int frameSize;
    int frameIndex;
    
    void (*setPosition)(struct Sprite* thiz, float top, float left);
    void (*setScale)(struct Sprite* thiz, float scale);
    void (*setAngle)(struct Sprite* thiz, float angle);
    void (*setCener)(struct Sprite* thiz, Point point);
    void (*setFlip)(struct Sprite* thiz, FlipMode Mode);
    void (*setFrame)(struct Sprite* thiz, int frame);
    void (*onUpdate)(struct Sprite* thiz, int ticks);
    void (*onDraw)(struct Sprite* thiz);
    void (*onKeyboard)(struct Sprite* thiz, Event event, int keyCode);
    void (*onMouse)(struct Sprite* thiz, Event event, Point point);
    void (*destroy)(struct Sprite* thiz);
} Sprite;

// Constructor function
Sprite* new_sprite(const char* image);
Sprite* new_spriteSheet(const char* image, Rect* frames, int frameSize);
void sprite_init(Sprite *thiz, const char *image, Rect* frames, int frameSize);
void sprite_on_update(Sprite *thiz, int ticks);
void sprite_on_keyboard(Sprite *thiz, Event event, int keyCode);
void sprite_on_mouse(Sprite *thiz, Event event, Point point);
void sprite_destroy(Sprite *thiz);

#endif // JUNIORIT_GAMECRAFT_SPRITE_H
