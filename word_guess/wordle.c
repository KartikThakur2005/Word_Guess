#include "src/game.h"
#include "src/animation.h"
#include "src/file.h"
#include "src/input.h"
#include "src/utils.h"
#include<stdio.h>
#include <stdbool.h>  
#include <assert.h>
#include<stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>
// FOR FLAPPY--------------------
#define xSize       32 
#define ySize       16 
#define pipeCount   3
#define GREEN       "\e[32m"
#define YELLOW      "\e[33m"
#define NC          "\e[0m"
typedef struct
{
    int x;
    int y;
} PIX;

PIX bird;
PIX pipes[3];
int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void Draw() {
    char buff[5000];
    strcpy(buff, "\e[17A");

    for (int y = 0; y <= ySize; y++) {
        for (int x = 0; x <= xSize; x++) {
            if (y == 0 || y == ySize || x == 0 || x == xSize) {
                strcat(buff, NC "[]");
                continue;
            }

            for (int i = 0; i < pipeCount; i++) {
                if (pipes[i].x >= x - 1 && pipes[i].x <= x + 1 &&
                    (pipes[i].y == y + 3 || pipes[i].y == y - 3)) {
                    strcat(buff, GREEN "[]");
                    goto bottom;
                } else if (pipes[i].x == x - 1 && pipes[i].y == y - 4) {
                    strcat(buff, GREEN "]/");
                    goto bottom;
                } else if (pipes[i].x == x && (pipes[i].y <= y - 4 || pipes[i].y >= y + 4)) {
                    strcat(buff, GREEN "][");
                    goto bottom;
                } else if (pipes[i].x == x + 1 && pipes[i].y == y - 4) {
                    strcat(buff, GREEN "\\[");
                    goto bottom;
                } else if (pipes[i].x == x - 1 && pipes[i].y == y + 4) {
                    strcat(buff, GREEN "]\\");
                    goto bottom;
                } else if (pipes[i].x == x + 1 && pipes[i].y == y + 4) {
                    strcat(buff, GREEN "/[");
                    goto bottom;
                } else if (pipes[i].x == x + 1 && (pipes[i].y <= y - 5 || pipes[i].y >= y + 5)) {
                    strcat(buff, GREEN " [");
                    goto bottom;
                } else if (pipes[i].x == x - 1 && (pipes[i].y <= y - 5 || pipes[i].y >= y + 5)) {
                    strcat(buff, GREEN "] ");
                    goto bottom;
                }
            }

            if (bird.y == y && bird.x == x) {
                strcat(buff, YELLOW ")>");
            } else if (bird.y == y && bird.x == x + 1) {
                strcat(buff, YELLOW "_(");
            } else if (bird.y == y && bird.x == x + 2) {
                strcat(buff, YELLOW " _");
            } else if (bird.y == y - 1 && bird.x == x) {
                strcat(buff, YELLOW ") ");
            } else if (bird.y == y - 1 && bird.x == x + 1) {
                strcat(buff, YELLOW "__");
            } else if (bird.y == y - 1 && bird.x == x + 2) {
                strcat(buff, YELLOW " \\");
            } else {
                strcat(buff, NC "  ");
            }

        bottom:;
        }
        strcat(buff, "\n");
    }
    printf(buff);
}

void Pipes() {
    for (int i = 0; i < pipeCount; i++) {
        if (pipes[i].x == -1) {
            (i == 0) ? (pipes[i].x = pipes[2].x + 15) : (pipes[i].x = pipes[i - 1].x + 15);
            pipes[i].y = (rand() % 7) + 5;
        }
    }
}

bool HitTest() {
    if (bird.y == 15) {
        printf("\nGame Over! You hit the ground.\n");
          // Pause for a couple of seconds before returning to the menu
        return true;  // Indicate a collision occurred
    }

    for (int i = 0; i < pipeCount; i++) {
        if (bird.x - 2 < pipes[i].x + 2 &&
            bird.x > pipes[i].x - 2 &&
            (bird.y < pipes[i].y - 2 || bird.y > pipes[i].y + 1)) {
            printf("\nGame Over! You hit a pipe.\n");
          // Pause for a couple of seconds before returning to the menu
            return true;  // Indicate a collision occurred
        }
    }
    return false;  // No collision
}

// ------------------------ For wordle
extern bool continuation;
extern int rounds;
extern bool corrects[5];
extern bool win;

#define ClrGreen "\033[0;32m"
#define ClrYellow "\033[0;33m"
#define ClrRed "\033[0;31m"
#define ClrStop "\033[0m"

bool continuation;
int rounds;
bool corrects[5];
bool win;

void my_assert(int condition) {
    if (!condition) {
        fprintf(stderr, "Assertion failed\n");
        exit(1);  
    }
}
void displayArcadeTitle() {
    printf("*******************************************\n");
    printf("*                                         *\n");
    printf("*             ARCADE GAME HUB             *\n");
    printf("*                                         *\n");
    printf("*******************************************\n\n");
}

void displayGamesMenu() {
    printf("Choose your game:\n");
    printf("1. Wordle\n");
    printf("2. Flappy Bird\n");
    printf("3. Exit\n");
}

void wordleGame() {
     int n;
    char *p;

    corrects[0] = false;
    corrects[1] = false;
    corrects[2] = false;
    corrects[3] = false;
    corrects[4] = false;

    rounds = 1;
    win = false;
    seed();

    n = readfile("src/final.txt"); 
    assert(!(n < 0));

    p = randomword(n);
    continuation = true;

    ani();

    while (continuation) {
        printf("\nROUND>%d\n", rounds);
        printf("\nEnter the word\n");
        gameloop(p);
        midani(rounds);
        rounds++;

        if (!win && rounds > 5) {
            win = false;
            continuation = false;
        }
    }

    printf("The correct word was: %s%s%s\n", ClrGreen, p, ClrStop);

    if (win) {
        printf("\n%s Congratulations, you won the game! %s\n", ClrGreen, ClrStop);
        happy();
    } else {
        printf("\n%s You lost the game %s\n", ClrRed, ClrStop);
        end();
    }

}

void flappyBirdGame() {
    srand(time(NULL));

    bird.x = 10;
    bird.y = 10;

    for (int i = 0; i < pipeCount; i++) {
        pipes[i].x = 25 + 15 * i;
        pipes[i].y = (rand() % 7) + 5;
    }

    int frame = 0;
    printf("Press W to jump and Q to quit.\n");

    for (int i = 0; i <= ySize; i++) {
        printf("\n");
    }

    Draw();

    while (1) {
        if (kbhit()) {
            char ch = getchar();
            if (ch == 'w' || ch == 'W') {
                bird.y -= 2;
            } else if (ch == 'q' || ch == 'Q') {
                break;
            }
        }

        if (frame == 2) {
            bird.y++;
            for (int i = 0; i < 3; i++) {
                pipes[i].x--;
            }
            frame = 0;
        }

        if (HitTest()) {
            break;  
        }

        Draw();
        Pipes();

        frame++;
        usleep(100000);  
    }
}

int main() 
{
    int choice;
    
    while(1) {
        system("clear"); 
        displayArcadeTitle();
        displayGamesMenu();
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                wordleGame();
                break;
            case 2:
                flappyBirdGame();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        sleep(2); 
    }
    
    return 0;
}
