#include "juniorit/GameCraft/Game.h"
#include "FirstScene.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    const char* name = "JuniorIT GameCraft App";

    int width = 1280;
    int height = 512;

    printf("%s starts; Scene width: %i, height: %i.\n", name, width, height);

    Game *game = game_instance();
    game->init(game, name, width, height);

    Scene *scene = (Scene *)new_first_scene();
    game->add_scene(game, scene);
    game->set_current_scene(game, scene);

    game->run(game);

    game->destroy(game);

    return 0;
}