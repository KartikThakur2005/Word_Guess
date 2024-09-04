#include "src/game.h"
#include "src/animation.h"
#include "src/file.h"
#include "src/input.h"
#include "src/utils.h"
#include<stdio.h>
#include <stdbool.h>  
#include <assert.h>
#include<stdlib.h>
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
int main() 
{
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

    return 0;
}