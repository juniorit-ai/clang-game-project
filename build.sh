#!/bin/bash

get_github_pages_url() {
    # Get the remote URL of the 'origin' remote
    remote_url=$(git remote -v | grep '^origin' | grep '(fetch)' | awk '{print $2}')

    # Check if the remote URL is in SSH or HTTPS format
    if [[ $remote_url == git@github.com:* ]]; then
        # SSH format
        repo_name=$(echo $remote_url | sed 's/git@github.com://;s/\.git$//')
    elif [[ $remote_url == https://github.com/* ]]; then
        # HTTPS format
        repo_name=$(echo $remote_url | sed 's/https:\/\/github.com\///;s/\.git$//')
    else
        echo "Error: Not a GitHub repository or unsupported URL format."
        return 1
    fi

    # Construct GitHub Pages URL
    user_name=$(echo $repo_name | cut -d'/' -f1)
    repo_name=$(echo $repo_name | cut -d'/' -f2)
    echo "https://$user_name.github.io/$repo_name"
}

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
    "deploy")
        cp -f web/* "$GAMECRAFT_PROJECT_PATH/web/"
        cd $GAMECRAFT_PROJECT_PATH
        git add .
        git commit -a -m "deploy at $(date)"
        git push
        echo
        echo "Your game has been deployed to `get_github_pages_url`, and you can share with your friends now."
        echo
        cd -
        exit 0
        ;;
    "submit")
        juniorit submit
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
