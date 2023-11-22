cmake_minimum_required(VERSION 3.10)

project(MyGame)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -gsource-map -Wno-unused-command-line-argument -Wno-limited-postlink-optimizations -s -O3 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS=['png','jpg'] --preload-file ../res@res")

set(CMAKE_EXECUTABLE_SUFFIX ".js")

include_directories(
    libs/GameCraft/include
    libs/GameCraft/src
    src
)

# Set the list of source files
set(SOURCE_FILES
    libs/GameCraft/src/Game.c
    libs/GameCraft/src/Scene.c
    libs/GameCraft/src/Sprite.c
    libs/GameCraft/src/utils.c
    src/FirstScene.c
    src/main.c
)

# Create the executable
add_executable(index ${SOURCE_FILES})

install(FILES
    .build/index.js
    .build/index.wasm
    .build/index.data
    .build/index.wasm.map
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/web)