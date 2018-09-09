# [C] Filler (42 project)

Leeets battle!

![Example](https://github.com/tbeauzam/42-project---filler/blob/master/videos/example_filler.gif)


### Main program

Filler is an algorithmic project. The aim here is to code a small AI called a Player. Then, the player have to fight another player in an "arena".
##### Rules:
- the game is played turn by turn. One player, then the other one, etc.
- each turn, the arena provides a random piece to be placed by the current player
- the player must place it in an empty space, with __exactly__ one pixel of the piece superposed with the pixels it already controls
- if a player can't place a piece, it dies!
- the player with the highest number of placed pieces wins.

![Validity](https://github.com/tbeauzam/42-project---filler/blob/master/videos/validity_example.png)

With these rules, it becomes obvious that the best way to win is by preventing the opponent to play.

### Usage:

After cloning:

```
make
./resources/filler_vm -p1 ./tbeauzam.filler -p2 ./resources/players/tbeauzam.filler -f ./resources/maps/map01
```
Where:
- *-p1 <path/to/player>* sets player 1 (character: O) and takes a player as parameter
- *-p2 <path/to/player>* sets player 2 (character: X) and takes a player as parameter
- *-f <path/to/map>* sets the arena. This should be a text file with at least one O, one X, and dots "." as empty pixels

In the *resource/players/* folder, many players can only be used on OSX operating systems (Sierra or El Capitan, not sure about it) while the few others can only run on Linux (Ubuntu and similars).

##### example of valid map:
```
.................
.................
.................
.................
.................
.................
.................
.................
..O..............
.................
.................
.................
..............X..
.................
.................
```

The command above should produce something that looks like this:

![Raw output](https://github.com/tbeauzam/42-project---filler/blob/master/videos/raw_output_filler.gif)

Ugly, isn't it?

### Visualizer

This is why I coded a visualizer using the ncurses library. It reads the raw output and displays it in a much nicer way. To use it:

```
./resources/filler_vm -p1 ./tbeauzam.filler -p2 ./resources/players/tbeauzam.filler -f ./resources/maps/map01 | ./visualizer
```

Player 1 is orange, players 2 is blue. 
The visualizer will not launch if terminal is too small (in case of a big map, by example). Resizing terminal or characters will fix it. It has some advanced features:
- replay function: possibility to scroll or use arrow keys to play each move forward or backward
- possibility to jump at the end, at the beginning of a game. Can also jump at the moment where the first player dies.

##### Some video where I use the different features in a random order:
![Example](https://github.com/tbeauzam/42-project---filler/blob/master/videos/visualizer_features_filler.gif)
