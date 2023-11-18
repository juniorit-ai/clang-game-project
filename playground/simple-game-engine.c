#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define GAME_FPS 60

// Definition of the GameSprite structure
struct GameSprite
{
    int x, y; // Coordinates of the sprite
    float scale; // Scaling factor of the sprite
    char image[50]; // File name for the sprite image
    void (*onUpdate)(struct GameSprite *thiz, int ticks); // Function pointer for onUpdate event
};

// Type definition for ease of use
typedef struct GameSprite Sprite;

// Function to update sprite properties per frame
// ticks - Time elapsed per frame in milliseconds
void sprite_on_update(Sprite *thiz, int ticks)
{
    // call linux clear shell command to clear screen
    system("clear");

    // Move sprite from right to left on the screen
    if (thiz->x == 0)
    {
        thiz->x = 100; // Reset position to right edge when reaching the left edge
    }

    thiz->x = thiz->x - 1; // Move left by one unit per frame

    for (int i = 0; i < thiz->x; i++) {
        printf(" ");
    }
    printf("*\n");
}

int main()
{
    // Create an instance of GameSprite
    struct GameSprite mySprite1;

    // Initialize properties
    mySprite1.x = 100; // Starting x-coordinate
    mySprite1.y = 10; // Starting y-coordinate
    mySprite1.scale = 1.5; // Starting scale

    const char *filename = "character sprite for demo only";
    strcpy(mySprite1.image, filename); // Copy image filename to sprite

    // Pointer to Sprite
    Sprite *sprite1;
    sprite1 = &mySprite1; // Assign the address of mySprite1 to sprite1

    // Modify properties via pointer
    sprite1->y = sprite1->y + 100; // Update y-coordinate
    sprite1->scale = sprite1->scale * 1.1; // Update scale

    // Assign function pointer
    sprite1->onUpdate = sprite_on_update;

    // Print sprite properties
    printf("Sprite1 Position: (%d, %d)\n", sprite1->x, sprite1->y);
    printf("Sprite1 Scale: %f\n", sprite1->scale);
    printf("Sprite1 Image: %s\n", sprite1->image);

    // Main game loop
    while (true)
    {
        int sleepMicrosecond = 1000000 / 30; // Game frame rate 30 fps;
        usleep(sleepMicrosecond); // Sleep to maintain frame rate

        int ticks = sleepMicrosecond / 1000; // Convert microseconds to milliseconds
        sprite1->onUpdate(sprite1, ticks); // Update sprite properties every frame
    }

    return 0;
}
