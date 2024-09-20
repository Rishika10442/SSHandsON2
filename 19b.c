/*
============================================================================
Name : 19b.c
Author : Rishika Gupta
Date: 19/9/24
19. Create a FIFO file by
b. mkfifo command*/
//============================================================================

#include <stdio.h>
#include <stdlib.h>

int main() {

    int s = system("mkfifo 19fifob");

    if (s == -1) {
        perror("mkfifo command failed");
        return 1;
    }

    printf("FIFO file created.\n");
    return 0;
}

//============================================================================
//FIFO file is created
