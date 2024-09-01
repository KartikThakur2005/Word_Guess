#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

extern bool continuation;
extern bool corrects[5];
extern bool win;
extern int rounds;

void gameloop(char *correct);
bool equal(char *corr, char *guess);
void isin(char c, char *correct);

#endif
