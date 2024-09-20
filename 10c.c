/*
============================================================================
Name : 10c.c
Author : Rishika Gupta
Date: 19/9/24
10. Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE*/
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>


void handler(int sig) {
    printf("Caught Floating Point Exception\n");
    exit(1);
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handler;

    sigaction(SIGFPE, &sa, NULL);

    int x = 5;
    int y = 0;
    int z = x / y;

   
    return 0;
}
//============================================================================
//Caught Floating Point Exception

