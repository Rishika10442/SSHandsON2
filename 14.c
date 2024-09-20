/*
============================================================================
Name : 14.c
Author : Rishika Gupta
Date: 19/9/24
14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.*/
//============================================================================

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    char w[] = "Hello pipe!";
    char r[100];
    
    
    pipe(pipefd);
    write(pipefd[1], w, strlen(w) + 1);
    read(pipefd[0], r, sizeof(r));
    printf("Message received: %s\n", r);

    close(pipefd[0]);
    close(pipefd[1]);
    
    return 0;
}
//============================================================================
//Message received: Hello pipe!

