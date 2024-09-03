#include "game.h"
#include "input.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include<assert.h>

#define ClrGreen "\033[0;32m"
#define ClrYellow "\033[0;33m"
#define ClrRed "\033[0;31m"
#define ClrStop "\033[0m"


extern bool continuation;
extern int rounds;
extern bool corrects[5];
extern bool win;
 

// Define your functions and other code here





void gameloop(char *correct) {
    char *input;
    input = readline();
    int len = strlen(input);

    if (len > 5 || len < 5) {
        printf(" \nPlease enter a valid string\n");
        return;
    } else if (equal(correct, input)) {
        continuation = false;
        win = true;
        return;
    } else {
        for (int i = 0; i < 5; i++) {
            isin(input[i], correct);
        }
    }

    printf("\n");

    for (int i = 0; i < 5; i++) {
        if (corrects[i]) {
            printf("%s%c%s", ClrYellow, correct[i], ClrStop);
        } else {
            printf("%s-%s", ClrRed, ClrStop);
        }
    }

    for (int i = 0; i < 5; i++) {
        corrects[i] = false;
    }

    printf("\n");
}

bool equal(char *corr, char *guess) {
    for (int i = 0; i < 5; i++) {
        if (corr[i] != guess[i]) {
            return false;
        }
    }
    return true;
}

void isin(char c, char *correct) {
    for (int i = 0; i < 5; i++) {
        if (correct[i] == c) {
            corrects[i] = true;
        }
    }
}
