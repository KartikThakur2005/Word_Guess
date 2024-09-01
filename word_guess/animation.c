#include "animation.h"
#include <stdio.h>
#include <unistd.h>

#define ClrGreen "\033[0;32m"
#define ClrYellow "\033[0;33m"
#define ClrRed "\033[0;31m"
#define ClrStop "\033[0m"

void ani() {
    printf(ClrRed);
    printf("+------------------------------------------------+\n");
    printf("|                                                |\n");
    printf("|          WELCOME TO THE Worlde GAME!           |\n");
    printf("|                                                |\n");
    printf("|        The SPY must be caught to save the KING!|\n");
    printf("|                Help the King!                  |\n");
    printf("|                                                |\n");
    printf("+------------------------------------------------+\n");
    printf(ClrStop);
}

void happy() {
sleep(1);
    printf(ClrGreen);
     printf("King's soldier captures the spy and starts beating him!\n");
        printf("+------------------------------------------------+\n");
        printf("|  KING          SOLDIER         %s%sSPY%s%s             |\n",ClrStop,ClrRed,ClrStop,ClrGreen);
        printf("|  \\o/            o             %s%so_x%s%s              |\n",ClrStop,ClrRed,ClrStop,ClrGreen);
        printf("|   |            /|\\            %s%s/|\\%s%s              |\n",ClrStop,ClrRed,ClrStop,ClrGreen);
        printf("|  / \\           / \\             %s%s/ \\%s%s             |\n",ClrStop,ClrRed,ClrStop,ClrGreen);
        printf("|                                                |\n");
        printf("%s|%s              %s*PUNCH* *KICK*%s                    %s|\n",ClrGreen,ClrStop,ClrRed,ClrStop,ClrGreen);
        printf("|                                                |\n");
        printf("+------------------------------------------------+\n");


     sleep(1);
      printf("\n\n");
        printf("The soldier is beating the spy!\n");
        printf("+------------------------------------------------+\n");
        printf("|  SOLDIER      %s%s*SPY*%s%s                            |\n",ClrStop,ClrRed,ClrStop,ClrGreen);
        printf("|    o         %s%so_x%s%s                               |\n",ClrStop,ClrRed,ClrStop,ClrGreen);
        printf("|   /|\\        %s%s/|\\%s%s                               |\n",ClrStop,ClrRed,ClrStop,ClrGreen);
        printf("|   / \\        %s%s/ \\%s%s                               |\n",ClrStop,ClrRed,ClrStop,ClrGreen);
        printf("|             %s%s*SPY IN PAIN*%s%s                      |\n",ClrStop,ClrRed,ClrStop,ClrGreen);
        printf("+------------------------------------------------+\n");

printf("\n\n");
  sleep(1);
        printf("+------------------------------------+\n");
    printf("|                                    |\n");
    printf("|     Y O U   H A V E   W O N       |\n");
    printf("|         T H E   G A M E            |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");
        printf(ClrStop);

}

void end() {
   sleep(1);
    printf(ClrRed);
    printf("\nSPY HAS REACHED THE KING!\n");
            printf("+------------------------------------------------+\n");
            printf("|  SPY ATTACKS THE KING!                          |\n");
            printf("|  \\o/        o                                  |\n");
            printf("|   |        /|\\      *stab*                     |\n");
            printf("|  / \\      / \\                                  |\n");
            printf("+------------------------------------------------+\n");

    sleep(1);

                printf("+------------------------------------------------+\n");
            printf("|              KING IS DEAD                      |\n");
            printf("|               X                                |\n");
            printf("|              /|\\                               |\n");
            printf("|              / \\                               |\n");
            printf("+------------------------------------------------+\n");
    
    printf("\n\n");
  sleep(1);
    printf("+------------------------------+\n");
    printf("|                              |\n");
    printf("|      G A M E   O V E R       |\n");
    printf("|                              |\n");
    printf("+------------------------------+\n");

      printf(ClrStop);

}

void midani(int rounds) {
    switch (rounds) {
        case 1:
            printf("+------------------------------------------------+\n");
            printf("|  KING                                           |\n");
            printf("|  \\o/                                  SPY      |\n");
            printf("|   |                                   o        |\n");
            printf("|  / \\                                 /|\\       |\n");
            printf("|                                       / \\      |\n");
            printf("+------------------------------------------------+\n");
            break;
        case 2:
            printf("+------------------------------------------------+\n");
            printf("|  KING                                           |\n");
            printf("|  \\o/                           SPY             |\n");
            printf("|   |                              o             |\n");
            printf("|  / \\                            /|\\            |\n");
            printf("|                                  / \\           |\n");
            printf("+------------------------------------------------+\n");
            break;
        case 3:
            printf("+------------------------------------------------+\n");
            printf("|  KING                                           |\n");
            printf("|  \\o/                     SPY                   |\n");
            printf("|   |                        o                   |\n");
            printf("|  / \\                      /|\\                  |\n");
            printf("|                             / \\               |\n");
            printf("+------------------------------------------------+\n");
            break;
        case 4:
            printf("+------------------------------------------------+\n");
            printf("|  KING                                           |\n");
            printf("|  \\o/               SPY                         |\n");
            printf("|   |                  o                         |\n");
            printf("|  / \\                /|\\                        |\n");
            printf("|                    / \\                         |\n");
            printf("+------------------------------------------------+\n");
            break;
        default:
            break;
    }
}
