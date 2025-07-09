# Arcadia X

Welcome to **Arcadia X**! This is a collection of classic and fun games implemented in C, all accessible from a single main menu. Each game is a standalone C program, and the hub provides a simple way to launch and play any of them.

## Table of Contents

- [Overview](#overview)
- [Games Included](#games-included)
- [How to Run](#how-to-run)
- [Game Descriptions](#game-descriptions)
- [File Structure](#file-structure)
- [Dependencies](#dependencies)
- [Notes](#notes)

---

## Overview

**Arcadia X** is a console-based application that allows users to select and play from a variety of games. The main menu (`Main Menu.c`) presents a list of available games, and the user can choose which one to play by entering the corresponding number.

---

## Games Included

1. **Tic Tac Toe** (`tic_tac_toe.c`)
2. **Hangman** (`hangman.c`)
3. **Ping Pong** (`ping_pong.c`)
4. **Mountain Ascend and Slip Stream** (`mountain_ascend.c`)
5. **Random Number Guesser** (`num_guesser.c`)
6. **Snake Game** (`snake.c`)
7. **Minesweeper** (`minesweeper.c`)
8. **Rock, Paper, Scissors** (`rock_paper.c`)
9. **Maze Escape** (`maze.c`)

---

## How to Run

1. **Compile the Main Menu:**
   - Use a C compiler (like GCC) to compile `Main Menu.c`. Make sure all game files are in the same directory or adjust the include paths as needed.
   - Example (Windows, using GCC):
     ```
     gcc "Main Menu.c" -o arcadia_x.exe
     ```

2. **Run the Executable:**
   - On Windows:
     ```
     arcadia_x.exe
     ```
   - On Linux/Mac (if ported and compatible):
     ```
     ./arcadia_x
     ```

3. **Follow the On-Screen Instructions:**
   - The main menu will display a list of games. Enter the number of the game you want to play.

---

## Game Descriptions

### 1. Tic Tac Toe (`tic_tac_toe.c`)
- Classic two-player game.
- Players take turns marking spaces in a 3×3 grid.
- The first to align three marks (horizontally, vertically, or diagonally) wins.

### 2. Hangman (`hangman.c`)
- Word guessing game.
- Guess letters to reveal a hidden word before running out of lives.
- Words are loaded from a file (`words.txt`).

### 3. Ping Pong (`ping_pong.c`)
- Console-based Pong game.
- Play against the computer, controlling a paddle to bounce the ball.

### 4. Mountain Ascend and Slip Stream (`mountain_ascend.c`)
- Roll an octagonal die to climb a mountain.
- Reach 100 steps to win, but beware of slip streams that can set you back.

### 5. Random Number Guesser (`num_guesser.c`)
- Guess a randomly selected number between 1 and 100.
- You have 10 attempts to guess correctly.

### 6. Snake Game (`snake.c`)
- Classic snake game.
- Control the snake to eat food and grow longer, avoiding collisions.

### 7. Minesweeper (`minesweeper.c`)
- Uncover safe spots on a grid without hitting a bomb.
- Numbers indicate how many bombs are adjacent.

### 8. Rock, Paper, Scissors (`rock_paper.c`)
- Play against the computer.
- First to win 3 rounds wins the game.
- Game results are saved to and can be viewed from a file (`gamefile.txt`).

### 9. Maze Escape (`maze.c`)
- Navigate a player through a maze from start ('S') to finish ('F').
- Use W/A/S/D keys to move.

---

## File Structure

```
/ (project root)
│
├── Main Menu.c           # Main menu and entry point
├── tic_tac_toe.c         # Tic Tac Toe game
├── hangman.c             # Hangman game
├── ping_pong.c           # Ping Pong game
├── mountain_ascend.c     # Mountain Ascend and Slip Stream game
├── num_guesser.c         # Random Number Guesser game
├── snake.c               # Snake game
├── minesweeper.c         # Minesweeper game
├── rock_paper.c          # Rock, Paper, Scissors game
├── maze.c                # Maze Escape game
├── words.txt             # (Required for Hangman, not included here)
├── gamefile.txt          # (Used by Rock, Paper, Scissors)
└── ...
```

---

## Dependencies

- **Compiler:** Any standard C compiler (GCC recommended).
- **Platform:** Windows (uses `conio.h`, `windows.h`, and `system("cls")` for clearing the screen).
- **Files:** 
  - `words.txt` (for Hangman) — should contain a list of words, one per line.
  - `gamefile.txt` (for Rock, Paper, Scissors) — created/used by the game.

---

## Notes

- The games use console input/output and may require a Windows environment for full compatibility (due to use of `conio.h` and `windows.h`).
- Some games prompt to play again or return to the main menu.
- Make sure all `.c` files are present in the same directory for the includes to work.
- For Hangman, ensure `words.txt` is present in the same directory.
- For Rock, Paper, Scissors, `gamefile.txt` will be created automatically.

---

## Credits

Developed as a fun project to bring together classic games in C. Each game is implemented in its own file for modularity and ease of understanding.

---
