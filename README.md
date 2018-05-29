# Fed in the Abyss

# Getting started

## prerequisites
as the game is console based, you'll need to install `ncurses` for C.

protips:
```bash
ncurses-devel.(your architecture) # fedora users
libncurses5-dev # ubuntu/debian users
```

to compile the game, make sure you have `premake5` (for creating the makefile) and `make` (for running it).

## installing
```bash
> premake5 gmake
> cd build
> make
> cd bin/Release
> ./roguelike
```
