# Hangman in C

A terminal-based Hangman game written in C.

The player tries to guess a hidden word by entering one letter at a time. Correct guesses reveal matching letters, while incorrect guesses reduce the remaining attempts. The game ends when the player guesses the word or runs out of chances.

## Features

- Random word selection
- Word hints loaded from an external text file
- Input validation
- Duplicate guess detection
- Reveals all matching letter occurrences
- ASCII hangman drawing
- Modular project structure using multiple source and header files
- Build automation using Makefile

## Project Structure

```
.
├── build
│   └── main
├── data
│   └── words.txt
├── include
│   ├── display.h
│   ├── helper.h
│   └── words.h
├── src
│   ├── display.c
│   ├── helper.c
│   ├── main.c
│   └── words.c
├── Makefile
└── README.md
```

### File Responsibilities

| File             | Description                                                |
| ---------------- | ---------------------------------------------------------- |
| `main.c`         | Contains the main game loop and program flow               |
| `words.c`        | Handles loading words and hints from the word database     |
| `display.c`      | Handles terminal output, word display, and hangman drawing |
| `helper.c`       | Contains input handling and guess validation utilities     |
| `include/`       | Contains header files for function declarations            |
| `data/words.txt` | Stores available words and hints                           |

## Requirements

- GCC compiler
- C17 compatible compiler
- Make

## Build and Run

Clone the repository:

```bash
git clone https://github.com/lhnsnm/hangman-game
cd hangman-game
```

Build the project:

```bash
make build
```

Run the game:

```bash
make run
```

Clean build files:

```bash
make clean
```

## Word File Format

The game loads words and hints from:

```
data/words.txt
```

Each entry follows this format:

```
word|hint
```

Example:

```
geeksforgeeks|Computer coding
elephant|A large mammal with a trunk
pizza|A popular Italian dish
beach|Sandy shore by the sea
```

## How It Works

1. The program loads available words and hints from `words.txt`.
2. A random word is selected.
3. The hidden word is displayed using underscores.
4. The player enters a letter guess.
5. The program checks:
   - Whether the input is a valid letter.
   - Whether the letter has already been guessed.
   - Whether the letter exists in the secret word.

6. Correct guesses reveal letters.
7. Incorrect guesses increase the number of failed attempts.
8. The player wins by revealing the entire word before the hangman is completed.

## Concepts Practiced

This project helped me practice:

- C structs
- Header files and source files
- Separate compilation
- Makefiles
- File I/O (`fopen`, `fgets`, `sscanf`)
- Arrays and character manipulation
- Boolean arrays as lookup tables
- String handling
- Functions and modular design
- Input validation
- Random number generation
- Working with pointers and arrays

## Future Improvements

Possible improvements:

- Add more word categories
- Add difficulty levels
- Track player scores
- Expand the word database
- Add automated tests
- Improve terminal graphics
- Add a configuration file for game settings

## Reference

This project was initially inspired by the GeeksforGeeks tutorial:

- [Hangman Game in C - GeeksforGeeks](https://www.geeksforgeeks.org/c/hangman-game-in-c/)

The tutorial was used as a starting point for learning the basic game logic. The project was then extended and refactored with additional features, including:

- Loading words and hints from an external text file
- Separating code into multiple source and header files
- Adding input validation
- Improving duplicate guess handling
- Creating a Makefile-based build system
