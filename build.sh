#!/bin/bash

(
export EMSCRIPTEN=/home/juniorit/emsdk/upstream/emscripten

case $1 in
    "clean")
        rm -rf .build
        echo "Cleaned .build folder"
        exit 0
        ;;
    "web")
        php -S localhost:9000 -t .
        exit 0
        ;;
    *)
        # for the rest
        ;;
esac

mkdir -p .build

cd .build/

cmake .. -DCMAKE_TOOLCHAIN_FILE=$EMSCRIPTEN/cmake/Modules/Platform/Emscripten.cmake

make
make install

cd ..
)
