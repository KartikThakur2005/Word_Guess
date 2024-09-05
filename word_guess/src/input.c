#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animation.h"

char *readline(void) {
    char *ret;
    char buf[1024];

    ret = malloc(16);
    fgets(buf, 1024, stdin);

    buf[5] = 0;
    memcpy(ret, buf, 6);

    return ret;
}
