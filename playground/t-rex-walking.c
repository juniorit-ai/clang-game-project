typedef enum FlipMode
{
    FLIP_NONE = 0,
    FLIP_HORIZONTAL = 1,
    FLIP_VERTICAL = 2,
    FLIP_DIAGONAL = 3
} FlipMode;

// Point structure
typedef struct Point
{
    float x;
    float y;
} Point;

// Rect structure
typedef struct Rect
{
    float top;
    float left;
    float width;
    float height;
} Rect;

// Sprite structure
typedef struct Sprite
{
    float top;
    float left;
    int width;
    int height;
    float scale;
    float angle;
    Point center;
    FlipMode flip;
    bool reDraw;
    void *texture;
    Rect *frames;
    int frameSize;
    int frameIndex;

    void (*setPosition)(struct Sprite *thiz, float top, float left);
    void (*setScale)(struct Sprite *thiz, float scale);
    void (*setAngle)(struct Sprite *thiz, float angle);
    void (*setCenter)(struct Sprite *thiz, Point point);
    void (*setFlip)(struct Sprite *thiz, FlipMode mode);
    void (*setFrame)(struct Sprite *thiz, int frame);
    void (*onUpdate)(struct Sprite *thiz, int ticks);
    void (*onDraw)(struct Sprite *thiz);
    void (*onKeyboard)(struct Sprite *thiz, Event event, int keyCode);
    void (*onMouse)(struct Sprite *thiz, Event event, Point point);
    void (*destroy)(struct Sprite *thiz);
} Sprite;

// Game fps: 60
void first_scene_on_update(FirstScene *thiz, int ticks)
{
    scene_on_update((Scene *)thiz, ticks);

    static int timeLapse = 0;

    timeLapse += ticks;

    float frequency = M_PI / 1000;
    float scale = 1 + 0.01 * sin(timeLapse * frequency);

    sprite->setScale(sprite, scale);

    // Move the sprite from left to right, then flip and move from right to left in the range of the screen (width 1280)
    float spriteWidth = sprite->width * sprite->scale;
    float spriteLeft = sprite->left;
    float spriteRight = spriteLeft + spriteWidth;
    float screenRight = background->width;;

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

void first_scene_init(FirstScene *thiz)
{
    Scene *scene = (Scene *)thiz;

    // Create a sprite for the background with size 1280x512
    background = new_sprite("background.png");
    scene->add_child(scene, background);

    // Create a sprite with size 342x218
    sprite = new_sprite("t-rex.png");
    scene->add_child(scene, sprite);

    // Set the sprite's top-left coordinate.
    sprite->setPosition(sprite, 250, 20);
    sprite->setFlip(sprite, FLIP_NONE);
}