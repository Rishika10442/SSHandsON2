/*============================================================================
Name : 19e.c
Author : Rishika Gupta
Date: 19/9/24*/
// mkfifo library function

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {

      if (mkfifo("19fifoe", 0666) == -1) {
        perror("mkfifo failed");
        return 1;
    }

    printf("FIFO file created.\n");
    return 0;
}
//============================================================================
//FIFO file created.
