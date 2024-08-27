#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max 200   
#define ResultGreen 1
#define ResultYellow 2
#define ResultRed 4

typedef char Result;
void gameloop(char *);
static char words[max][5];
bool continuation;  
void seed(void);
char *randomword(int);

struct s_words
{
    char **arr;
    int n;
};

typedef struct s_words Words; 

int readfile(char*);
bool isin(char, char*);
void Example_print(Result*, char*, char*);
Result* cw(char*, char*);
Result cc(char, int, char*);

int main(int, char**);

void promt(int arr[])

void Example_print(Result* res, char *guess, char *correct)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        switch (res[i])
        {
            case ResultGreen:
               
                printf("%s%c%s", ClrGreen, guess[i], ClrStop);
                break;

            case ResultYellow:
                 printf("%s%c%s", ClrYellow, guess[i], ClrStop);
                break;

            case ResultRed:
               printf("%s%c%s", ClrRed, guess[i], ClrStop);
                break;

            default:
                printf("unknown : %d\n", res[i]);
             
                break;
        }
    }

    printf("\n");
    return;
}


char * randomword(int m)
{
    int x;
    
    static char ret[8];

    x = rand() %m;

    ret [0] = words[x][0];
    ret [1] = words[x][1];
     ret [2] = words[x][2];
    ret [3] = words[x][3];
     ret [4] = words[x][4];
     ret[5] = 0;

     return ret;
}

bool isin(char c, char* str)
{
    int i, size;
    size = strlen(str);

    for (i = 0; i < size; i++)
    {
        if (str[i] == c)
        {
            return true;
        }
    }
    return false;
}

Result cc(char guess, int idx, char *word)
{
    char correct = word[idx];

    if (guess == correct)
        return ResultGreen;
    else if (isin(guess, word))
        return ResultYellow;

    return ResultRed;
}


int readfile(char* filename)
{
    char buf[8];
    int i, size;
    FILE *fd;

    fd = fopen(filename, "r");

    if (!fd)
    {
        perror("fopen error");
        return -1;
    }

    i = 0;
    memset(buf, 0, 8);

    while (fgets(buf, 7, fd))
    {
        size = strlen(buf);

        if (size < 1)
        {
            memset(buf, 0, 8);
            continue;
        }

        size--; // Strip the newline character
        buf[size] = 0;

        if (size != 5)
        {
            memset(buf, 0, 8);
            continue;
        }

        // Store word in words array
        words[i][0] = buf[0];
        words[i][1] = buf[1];
        words[i][2] = buf[2];
        words[i][3] = buf[3];
        words[i][4] = buf[4];

        // // Debug print to verify the word
        // printf("Word %d: %s\n", i + 1, buf);  // Printing the buffer
        // printf("Stored: %c%c%c%c%c\n", words[i][0], words[i][1], words[i][2], words[i][3], words[i][4]);

        memset(buf, 0, 8);
        i++;

        if (max <= i) break;
    }

    fclose(fd);
    return i;
}


Result* cw(char *guess, char *word)
{
    static Result res[5];
    int i;

    for (i = 0; i < 5; i++)
    {
        res[i] = cc(guess[i], i, word);
    }

    return res;
}

void seed()
{
    int x = getpid();

    srand(x);
    return;
}


void gameloop(char *correct)
{
   
}

int main(int argc, char *argv[])
{
    int n;
    n = readfile("final.txt");

    seed();

    char *p;
    p = randomword(n);

    // if (n < 0)
    // {
    //     printf("Failed to open\n");
    // }
    // else
    // {
    //     // printf("Total Words: %d\n", n);

    //     // // Print the 11th word to check correct storage
    //     // printf("Word 11: %c%c%c%c%c\n", words[10][0], words[10][1], words[10][2], words[10][3], words[10][4]);
        
    //     // // Print all words (optional, remove if file is large)
    //     // for (int i = 0; i < n; i++)
    //     // {
    //     //     printf("Word %d: %c%c%c%c%c\n", i + 1, words[i][0], words[i][1], words[i][2], words[i][3], words[i][4]);
    //     // }

    //     printf("word : %s\n",randomword(n));
    // }

    assert(!(n < 0 ));

    continuation = true;

    while (continuation)
    {
        gameloop(p);
    }
    

    return 0;
}
