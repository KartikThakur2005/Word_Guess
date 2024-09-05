#include "file.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "animation.h"

#define max 22

static char words[max][5];

int readfile(char *filename) {
    char buf[8];
    int i, size;
    FILE *fd;

    fd = fopen(filename, "r");

    if (!fd) {
        perror("fopen");
        return -1;
    }

    memset(buf, 0, 8);
    i = 0;

    while (fgets(buf, 7, fd)) {
        size = strlen(buf);

        if (size < 1) {
            memset(buf, 0, 8);
            continue;
        }

        size--;
        buf[size] = 0;

        if (size != 5) {
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

        if (max <= i) {
            break;
        }
    }

    fclose(fd);

    return i;
}

char *randomword(int m) {
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
