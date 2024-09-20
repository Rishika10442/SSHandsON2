/*
============================================================================
Name : 17a.c
Author : Rishika Gupta
Date: 19/9/24
17. Write a program to execute ls -l | wc.
a. use dup */
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefdes[2]; 
    pid_t pid1, pid2;

    
    pipe(pipefdes);
    pid1 = fork();
   

    if (pid1 == 0) {
        close(STDOUT_FILENO);

       
        if (dup(pipefdes[1]) == -1) {
            perror("dup");
            exit(EXIT_FAILURE);
        }
        close(pipefdes[0]);
        close(pipefdes[1]);

        execlp("ls", "ls", "-l", NULL);
    
    }

    
    pid2 = fork();
   

    if (pid2 == 0) {
        close(STDIN_FILENO);
        if (dup(pipefdes[0]) == -1) {
            perror("dup");
            exit(EXIT_FAILURE);
        }
        close(pipefdes[0]);
        close(pipefdes[1]);
        execlp("wc", "wc", NULL);
       
    }

    close(pipefdes[0]);
    close(pipefdes[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}
//============================================================================
//36     317    2326
