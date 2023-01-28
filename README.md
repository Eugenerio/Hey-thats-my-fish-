# Hey-thats-my-fish-

#  Penguin Game
This is a simple penguin game where players take turns placing and moving penguins on a square board. The goal of the game is to have the most penguins on the board at the end.

# How to Play
* Start the game by running the [compileNRun.bat] file in a C compiler.
* Enter the number of players (minimum 2, maximum 8)
* Enter the number of penguins per player (minimum 1, maximum 10)
* Enter the dimensions of the board (minimum 5, maximum 50)
* The board will be generated and displayed. Players will take turns placing their penguins on the board.
* Once all penguins have been placed, players will take turns moving their penguins.
* The game ends when all players have passed their turn. The player with the most penguins on the board wins.
# Requirements
* C compiler
* **stdio.h**, **time.h**, **stdlib.h**, **ui.h**, **board.h**, **placement.h**, and **movement.h** header files.
#Additional notes
* The **ui.h**, **board.h**, **placement.h**, and **movement.h** files are included in the project and should not be modified.
* The **struct.h** file contains the global constants and structs used in the game.
* The game uses ANSI escape codes to change the text color, so it may not work properly on all terminals.
