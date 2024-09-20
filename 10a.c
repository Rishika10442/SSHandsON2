/*
============================================================================
Name : 10a.c
Author : Rishika Gupta
Date: 19/9/24
10. Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
*/
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>


void handler(int sig) {
    printf("Caught signal Segmentation Fault\n");
    exit(1);
}

int main() {
    
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handler;
    sigaction(SIGSEGV, &sa, NULL);
    int *ptr = NULL;
    *ptr = 42;

    return 0;
}
//============================================================================
//Caught signal Segmentation Fault
