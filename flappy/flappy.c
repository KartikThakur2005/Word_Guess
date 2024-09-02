#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

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

void HitTest() {
    if (bird.y == 15) {
        exit(0);
    }

    for (int i = 0; i < pipeCount; i++) {
        if (bird.x - 2 < pipes[i].x + 2 &&
            bird.x > pipes[i].x - 2 &&
            (bird.y < pipes[i].y - 2 || bird.y > pipes[i].y + 1)) {
            exit(0);
        }
    }
}

int main() {
    srand(time(NULL));

    bird.x = 10;
    bird.y = 10;

    for (int i = 0; i < pipeCount; i++) {
        pipes[i].x = 25 + 15 * i;
        pipes[i].y = (rand() % 7) + 5;
    }

    int frame = 0;
    printf("Press UP to jump and Q to quit.\n");

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

        HitTest();
        Draw();
        Pipes();

        frame++;
        usleep(100000); // 100ms delay
    }

    return 0;
}
