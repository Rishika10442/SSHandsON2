/*
============================================================================
Name : 19a.c
Author : Rishika Gupta
Date: 19/9/24
19. Create a FIFO file by
a. mknod command*/
//============================================================================
#include <stdio.h>
#include <stdlib.h>

int main() {

    int s = system("mknod 19myfifoa p");
    if (s == -1) {
        perror("mknod failed");
        return 1;
    }

    printf("FIFO file is created.\n");
    return 0;
}
//============================================================================
//FIFO file is created.
