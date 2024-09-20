//mknod system call
/*============================================================================
Name : 19d.c
Author : Rishika Gupta
Date: 19/9/24*/
//============================================================================
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {

    if (mknod("19fifod", S_IFIFO | 0666, 0) == -1) {
        perror("mknod failed");
        return 1;
    }

    printf("FIFO file created.\n");
    return 0;
}
//============================================================================
//FIFO file created
