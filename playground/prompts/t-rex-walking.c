
typedef enum FlipMode {
    FLIP_NONE = 0,
    FLIP_HORIZONTAL = 1,
    FLIP_VERTICAL = 2,
    FLIP_DIAGONAL = 3 
} FlipMode;

// Sprite structure 
typedef struct Sprite {
    float top;
    float left;
    int width; 
    int height; 
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
    // ticks - Time elapsed per frame in milliseconds
    void (*onUpdate)(struct Sprite* thiz, int ticks);
    void (*onDraw)(struct Sprite* thiz);
    void (*onKeyboard)(struct Sprite* thiz, Event event, int keyCode);
    void (*onMouse)(struct Sprite* thiz, Event event, Point point);
    void (*destroy)(struct Sprite* thiz);
} Sprite;

// game fps: 60
void first_scene_on_update(FirstScene *thiz, int ticks)
{
    scene_on_update((Scene *)thiz, ticks);

    static int timeLapse = 0;

    timeLapse += ticks; 

    float frequency = M_PI / 1000;
    float scale = 1 + 0.01 * sin(timeLapse * frequency);

    sprite->setScale(sprite, scale);

    // TODO: move the sprite from left to right, then flip and move from right to left in the range of the screen (width 1280)
}

void first_scene_init(FirstScene *thiz)
{

    Scene *scene = (Scene *)thiz;

    // size - width: 1280, height 512
    background = new_sprite("background.png");
    scene->add_child(scene, background);

    // size - width: 342, height: 218
    sprite = new_sprite("t-rex.png");

    scene->add_child(scene, sprite);

    // Set the sprite's top-left coordinate.
    sprite->setPosition(sprite, 250, 20);
    sprite->setFlip(sprite, FLIP_NONE);
    
}