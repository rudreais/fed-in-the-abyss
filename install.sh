#!/usr/bin/env bash


#TODO checker tous les includes
NCURSES_HEADER=/usr/include/ncurses.h
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
DESKTOP_APP_DIR='/usr/share/applications/'
EXEC_COMMAND="bash -c 'cd $DIR; ./fita'"
ICON_PATH=$DIR'/fita.png'
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

create_desktop_app() {
    read -p "Do you want to add the game to your desktop ? y\N" -n 1 -r
    echo
    if [[ $REPLY =~ ^[Yy]$ ]]; then
        if printf "[Desktop Entry]\nEncoding=UTF-8\nVersion=1.0\nType=Application\nTerminal=true\nExec=%s\nName=fed-in-the-abyss\nIcon=%s\n" "$EXEC_COMMAND" "$ICON_PATH" > ${DESKTOP_APP_DIR}/fita.desktop; then
            return 0
        else
            return 1
        fi
    else
        echo "You can launch the game by typing ./fita in the fed-in-the-abyss directory"
    fi
}

if [ "$EUID" -ne 0 ]
  then echo -e "${RED}Installation script needs root privilege. Try again using sudo please.${NC}"
  exit
fi

#TODO add auto install ncurses depending on OS
if [ ! -f $NCURSES_HEADER ]; then
    echo -e "${RED}Ncures not found please install it and try again.${NC}"
    exit 1
fi

if make re -silent -C $DIR; then
    if create_desktop_app; then
        echo -e "${GREEN}Everything went well. You can launch the game by executing ./fita in the game directory.${NC}"
    else
        echo -e "${RED}An error occured during desktop app creation.${NC}"
    fi
else
    echo -e "${RED}An error occured during compilation.${NC}"
    exit 1
fi