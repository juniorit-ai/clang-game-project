#include "juniorit/GameCraft/Game.h"
#include "FirstScene.h"
#include <stdio.h>

/*
  Pre-knowledge of Basic C Before Starting

  1. How to define an int and a Game variable?

     int width;
     Game game;

  2. How to access the member/data of a variable?

     int width; // int type is a basic type in C, and basic types have no members
     printf("The width is: %i", width);

     Game game; // Game is a complex type with members
     printf("The width of the game window: %i", game.width);

  3. How to get the memory address (pointer) of a variable?

     int* pWidth = &width; // a data type with * is a pointer/address 
     Game* pGame = &game; // we use & to get the address of a variable

  4. How to access the member/data of an address (pointer)?

     int* pWidth = &width;
     Game* pGame = &game;

     printf("The width is: %i", *pWidth); // we use * to get the data pointed to by an address (pointer)
     printf("The width of the game window: %i", pGame->width); // we use -> to access the member of an address (pointer)

  5. Sometimes we use a 'p' prefix to indicate that a variable is a pointer, for example, 'int* pWidth', 'Game* pGame', to make the code more readable.
     However, since pointers are commonly used for complex types in C, we often omit the 'p' prefix for such types. For instance, we use 'Game* game' instead of 'Game* pGame'.
*/


int main(int argc, char *argv[])
{
    int width = 1280;
    int height = 512;

    printf("T-Rex game starts; Scene width: %i, height: %i.\n", width, height);

    // game_instance() alway returns the same game instance. If it does not exist the game_instance() will create a new one  - singleton design pattern
    Game* game = game_instance();

    // initialize the game instance, as C is not an object oriented programming language, 
    // we need to pass the game variable to the init function to let the function knows the function is to initialize which variable
    game->init(game, width, height);

    // create our first scene of the game, it is our major game logic
    Scene* scene = (Scene*)new_first_scene();

    // add the scene to the game, so the game engine can show this scene, one game can have multiple scenes 
    game->add_scene(game, scene);

    // set the sence as the current scene in the game, one game can only show one scene at one time
    game->set_current_scene(game, scene);

    // start the game loop, it will make the game keep running until quit the game by user
    game->run(game);

    // release all the memory
    // any scenes (and sprites added to the scene) added to the game will be destroyed too
    // so we just need to destroy game instance in the end once, and don't need to destroy others
    game->destroy(game);

    return 0;
}
