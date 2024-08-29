#define _GNU_SOURCE  
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include<assert.h>
#include<errno.h>

#define ResultGreen 1
#define ResultYellow 2
#define ResultRed 4
#define max 22
#define ValOk 0
#define ValBadInput 1
#define ValNoSuchWord 2

#define ClrGreen "\033[0;32m"
#define ClrYellow "\033[0;33m"
#define ClrRed "\033[0;31m"
#define ClrStop  "\033[0m"



typedef char ValResult;
typedef char Result;
bool continuation;
int rounds;
bool corrects[5];
bool win;


char *readline(void);
void prompt(char*);
static char words[max][5];
void gameloop(char*);
void seed(void);
char *randomword(int);
int readfile(char*);
void isin(char, char*);  


void ani()
{

           printf(ClrRed);
           printf("+------------------------------------------------+\n");
            printf("|                                                |\n");
            printf("|          WELCOME TO THE Worlde GAME!           |\n");
            printf("|                                                |\n");
            printf("|        The SPY must caught  to save the KING   |\n");
            printf("|                Help the King                   |\n");
            printf("|                                                |\n");
            printf("+------------------------------------------------+\n");

            printf(ClrStop);
        
        
        
}

void happy()
{
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

void end()
{
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

void midani(int rounds)
{
    printf("\n\n");
    switch (rounds) {
        case 1:
            printf("+------------------------------------------------+\n");
            printf("|  %sKING%s                                           |\n",ClrGreen,ClrStop);
            printf("|  %s\\o/%s                                  %sSPY%s      |\n",ClrGreen,ClrStop,ClrRed,ClrStop);
            printf("|   %s|%s                                   %so%s        |\n",ClrGreen,ClrStop,ClrRed,ClrStop);
            printf("|  %s/ \\%s                                 /|\\       |\n",ClrGreen,ClrStop);
            printf("|                                       %s/ \\%s      |\n",ClrRed,ClrStop);
            printf("+------------------------------------------------+\n");
            break;
        case 2: 
            printf("+------------------------------------------------+\n");
            printf("|  %sKING%s                                           |\n",ClrGreen,ClrStop);
            printf("|  %s\\o/%s                           %sSPY%s             |\n",ClrGreen,ClrStop,ClrRed,ClrStop);
            printf("|   %s|%s                              %so%s             |\n",ClrGreen,ClrStop,ClrRed,ClrStop);
            printf("|  %s/ \\%s                            %s/|\\%s            |\n",ClrGreen,ClrStop,ClrRed,ClrStop);
            printf("|                                  %s/ \\%s           |\n",ClrRed,ClrStop);
            printf("+------------------------------------------------+\n");
            break;
        case 3:
            printf("+------------------------------------------------+\n");
            printf("|  %sKING%s                                           |\n",ClrGreen,ClrStop);
            printf("|  %s\\o/%s                     %sSPY%s                   |\n",ClrGreen,ClrStop,ClrRed,ClrStop);
            printf("|   %s|%s                      %so%s                     |\n",ClrGreen,ClrStop,ClrRed,ClrStop);
            printf("|  %s/ \\%s                    %s/|\\%s                    |\n",ClrGreen,ClrStop,ClrRed,ClrStop);
            printf("|                         %s/ \\%s                    |\n",ClrRed,ClrStop);
            printf("+------------------------------------------------+\n");
            break;
        case 4:
            printf("+------------------------------------------------+\n");
            printf("|  %sKING%s                                           |\n",ClrGreen,ClrStop);
            printf("|  %s\\o/%s             %sSPY%s                           |\n",ClrGreen,ClrStop,ClrRed,ClrStop);
            printf("|   %s|%s              %so%s                             |\n",ClrGreen,ClrStop,ClrRed,ClrStop);
            printf("|  %s/ \\%s            %s/|\\%s                            |\n",ClrGreen,ClrStop,ClrRed,ClrStop);
            printf("|                 %s/ \\%s                            |\n",ClrRed,ClrStop);
            printf("+------------------------------------------------+\n");
            break;
        case 5:
            printf("+------------------------------------------------+\n");
            printf("|  %sKING%s                %sSPY%s                        |\n",ClrGreen,ClrStop,ClrRed,ClrStop);
            printf("|  %s\\o/%s                %so%s                          |\n",ClrGreen,ClrStop,ClrRed,ClrStop);
            printf("|   %s|%s                %s/|\\%s                         |\n",ClrGreen,ClrStop,ClrRed,ClrStop);
            printf("|  %s/ \\%s               %s/ \\%s                         |\n",ClrGreen,ClrStop,ClrRed,ClrStop);
            printf("+------------------------------------------------+\n");
            break;;

            
    }
    printf("\n\n");

}

char *randomword(int m)
{
   int x;
    static char ret[8];
   x = rand() % max;

 ret[0] = words[x][0];
 ret[1] = words[x][1];
 ret[2] = words[x][2];
 ret[3] = words[x][3];
 ret[4] = words[x][4]; 

 ret[5] = 0; 

 return ret;
}






int readfile(char *filename)
{
    char buf[8];
    int i,size;

    FILE *fd;
  
    

    fd = fopen(filename, "r");

    if (!fd)
    {
        
        perror("fopen");
        return -1;
    }

    

    memset(buf, 0, 8);

    i = 0;
    while (fgets(buf, 7, fd))
    {
            size = strlen(buf);

            if (size < 1)
            {
                  memset(buf, 0, 8);
                  continue;
            }
            

            size--;
            buf[size] = 0;

            if (size != 5)
            {
                 memset(buf, 0, 8);
                  continue;
            }
            
            words[i][0] = buf[0];
            words[i][1] = buf[1];
            words[i][2] = buf[2];
            words[i][3] = buf[3];
            words[i][4] = buf[4];

            memset(buf, 0, 8);
            i++;

            if ( max <= i)
            {
                break;
            }
            
    }

    fclose(fd);
    
    
        return i;
    
}

void seed()
{
    int x;

    x = getpid();
    srand(x);
    return;
}

char *readline()
{
   static char buf[8];
    int size;

    memset(buf, 0, 8);
    fgets(buf, 7, stdin);
    size = strlen(buf);
     assert(size > 0);
    size--;

    buf[size] = 0;
    
    return buf;
}



bool equal(char *corr, char *guess)
{
    for ( int i = 0; i < 5; i++)
    {
        if (corr[i] != guess[i])
        {
            return false;
        }
        
    }
    return true;
    
}

void isin(char c, char *correct)
{
    for (int i = 0; i < 5; i++)
    {
         if (correct[i] == c)
         {
             corrects[i] = true;
         }
         
    }
    

}
void gameloop(char *correct)
{
    char *input;
    input = readline();
    int len = strlen(input);

    if (len> 5 || len<5)
    {
        printf(" \n Please enter valid string \n");
        return;

    }
    else if (equal(correct, input))
    {
        continuation = false;
        win = true;
        return;
    }

    else 
    {
         for (int i = 0; i < 5; i++)
         {
            isin(input[i], correct);
         }
         
    }
 printf("\n");

    for (int i = 0; i < 5; i++)
    {
        if (corrects[i])
        {
        
            printf("%s%c%s",ClrYellow , correct[i], ClrStop);
            
        }
        else
        {
            printf("%s-%s", ClrRed, ClrStop);
        }
        
    }
     for (int i = 0; i < 5; i++)
    {
          corrects[i] = false;        
    }
    printf("\n");
    

    return ;
}

int main(int ,char**);

int main(int argc, char *argv[])
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
     n = readfile("final.txt");
     assert(!(n<0));

     p = randomword(n);
     continuation = true;

      ani();
      printf("\n%s\n",p);
     while (continuation)
     {
         printf("\nROUND>%d\n", rounds);
          printf("\nEnter the word\n");
          gameloop(p);
          midani(rounds);
          rounds++;
          
          if (win == false && rounds >5)
        {
        
          win = false;
          continuation = false;
        }


     }
     printf("The correct word was : %s %s %s\n", ClrGreen, p, ClrStop);

     if (win)
     {
         printf("\n %s Congratulation, you won the game %s\n", ClrGreen, ClrStop);

         happy();
     }
     else
     {
        printf("\n %s You lost the game\n %s", ClrRed, ClrStop);
        end();
     }
     
      

    return 0;
}