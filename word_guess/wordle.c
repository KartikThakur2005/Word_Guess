/*final.txt*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max 100
#define ResultGreen 1
#define ResultYellow 2
#define ResultRed 4



typedef  char Result;

struct s_words
{
     char **arr;
     int n;
};

typedef struct s_words Words; 



bool isin(char,char*);
void Example_print(Result*);
Result* cw(char*, char*);

Result cc(char, int, char*);

int main(int,char**);

void Example_print(Result* res)
{
    int i;

    for ( i = 0; i < 5; i++)
    {
        switch (res[i])
        {
            case ResultGreen:
            printf("%s\n", "Green");
            break;
            
            case ResultYellow:
             printf("%s\n", "Yellow");
            break;
            
            case ResultRed:
             printf("%s\n", "Red");
            break;
            
            default:
            printf("unnknown : %d\n", res[i]);
            break;

        }
    }
    return;
    
}


bool isin(char c, char* str)
{
    bool ret;
    int i, size;
    
    ret = false;

    size = strlen(str);

    for ( i = 0; i <size; i++)
    {
        if (str[i] == c)
        {
            ret = true;
            break;
        }
    
        
    }
    return ret;
    
}

Result cc(char guess, int idx, char *word)
{
    char correct;
    correct = word[idx];
 
    if (guess == correct)return ResultGreen;
    else if (isin(guess, word)) return ResultYellow;
    
    
    return ResultRed;
   
}

Words readfile(char* filename)
{
     char buf[8];
     int i, size;

     FILE *fd;
 
    static char ret[max][5];
     
     fd = fopen(filename, "r");

     if (!fd)
     {
         perror("fopen erro");
       Words words = 
        {
            .arr = (char **)0,
            .n = 0,
        };

         return words;
     };

  
  i = 0;
  memset(buf, 0, 8);

  while ( fgets(buf, 7, fd))
  {
     size = strlen(buf);

     if ( size < 1)
     {
         memset(buf, 0, 8);
        continue;
     }
     

     size --;

     buf[size] = 0;

     if (size != 5)
     {
        memset(buf, 0 ,8);
        continue;
     }

     ret[i][0] = buf[0];
    ret[i][1] = buf[1];
     ret[i][2] = buf[2];
     ret[i][3] = buf[3];
     ret[i][4] = buf[4];
     
     memset(buf, 0, 8);
     i++;

     if (max <= i) break;
     
     
  }

  fclose(fd);

Words words = 
  {
     .arr = (char **) &ret,
     .n = i,
  };

  return words;
  
  
   

     

}

Result* cw(char *guess, char *word)
{
    static Result res[5];
    int i;

    for(i = 0; i < 5; i++){ 
     res[i] = cc(guess[i], i, word);
    }

     return res; 
    
}


int main(int argc, char *argv[])
{
  char *correct, *guess;
  Result *res; 

    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s CORRECT WORD GUESS\n", argv[0]);
        return -1;
    }

   
    correct = argv[1];
     guess = argv[2];
    

    res = cw(guess, correct);

    Example_print(res);
    
    
    return 0;
}
