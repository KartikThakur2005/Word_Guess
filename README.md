# Arcade 🎮🎮

 Description: A multi-game arcade has 2 different games in one machine
             1> Wordle
             2> Flappy bird


  ![image](https://github.com/user-attachments/assets/a7ce2496-652b-423f-9fb0-6877b21fe8ca)



 ![image](https://github.com/user-attachments/assets/d6fd9cd6-4051-4d66-95e4-a7ac84f37bc5)


## Table of Contents
- Feature of Games
- Requirements
- Installation
         - Linux
          - Windows
- Usage
- Running the Game



## Features of Wordle

- Randomly selects a word from a  wordlist.

- Allows players to guess letters.

![image](https://github.com/user-attachments/assets/14107781-c2ac-4c18-820e-6277129f17c7)

- Displays the current progress of the guessed word.
![image](https://github.com/user-attachments/assets/91088780-7eb4-497e-8680-1ce814bbaf98)

- Provides feedback on correct and incorrect guesses.

- Limits the number of incorrect guesses.

- Displays a simple end screen showing the result of the game (win/lose).

 ![image](https://github.com/user-attachments/assets/4904b289-d7d5-436c-8b7c-549a4c0ab7e2)


## How to Run the Project

- To run this application place all the files in one folder

 ![image](https://github.com/user-attachments/assets/88983dfc-368e-4b67-8e02-47eb37418693)

 - To compile all the files use    gcc -o wordle wordle.c -L. -my_lib

 - To run gem type ./wordle
 ![image](https://github.com/user-attachments/assets/9db9788b-c88f-4ccb-a7cd-5324a059dd20)

## Header files for Linux OS
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

## Header files for Window OS

Use #include <conio.h>   instead of #include <termios.h>
Use #include #include <windows.h>   instead of #include <unistd.h>

## How to play Game

- Type 1 for Wordle
- Type 2 for Flappy word
- Type 3 for exiting 


- ![image](https://github.com/user-attachments/assets/e3cb1e28-7af8-4838-8b8c-bf2e2bbf3611)
