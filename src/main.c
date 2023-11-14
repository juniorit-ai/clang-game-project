#include "juniorit/GameCraft/Game.h"
#include "FirstScene.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Start ...\n");

    Game* game = game_instance();
    
    game->init(game, 1280, 512);

    Scene* scene = (Scene*)new_first_scene();

    game->add_scene(game, scene);
    game->set_current_scene(game, scene);

    game->run(game);

    game->destroy(game);

    return 0;
}
