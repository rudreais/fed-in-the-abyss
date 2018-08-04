 # TODO
`refactoring` is what you can do to help me.

`dev` is what I have to do (implementing features)

## refactoring
- `attack()`: delete `cursor_t backup` as it was only for a test
- `files_init()`: refactor this function as its taking too much time to launch the game. also, close dir, freeing memory.

## dev
- add enemies:
	- random generation based on the player position
	- difficulty increasing based on the player level
- use experience gained to level up:
	- stop experience at a certain level based on the actual floor
- make a minimap (mostly for fun lol)
