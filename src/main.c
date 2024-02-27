#include "juniorit/GameCraft/Game.h"
#include "FirstScene.h"
#include <stdio.h>

/*
   The following code initializes a basic JuniorIT GameCraft application.
   It includes necessary headers, sets up the game parameters, creates and adds
   the first scene, and runs the game loop.
*/

int main(int argc, char *argv[])
{
    // Initializing the name, width, and height
    const char* name = "JuniorIT GameCraft App";
    int width = 1280;
    int height = 512;

    // Printing the start message with application details
    printf("%s starts; Scene width: %i, height: %i.\n", name, width, height);

    // Initializing the game and setting up the first scene
    Game *game = game_instance();
    game->init(game, name, width, height);

    // Creating and adding the first scene to the game
    Scene *scene = (Scene *)new_first_scene();
    game->add_scene(game, scene);
    game->set_current_scene(game, scene);

    // Running the game
    game->run(game);

    // Cleaning up and destroying the game
    game->destroy(game);

    return 0;
}
