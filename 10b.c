/*
============================================================================
Name : 10b.c
Author : Rishika Gupta
Date: 19/9/24
10. Write a separate program using sigaction system call to catch the following signals.
b. SIGINT*/
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>


void handler(int sig) {
    printf(" Caught signal SIGINT");
	exit(0);
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handler;
    sigaction(SIGINT, &sa, NULL);
    while (1);

    return 0;
}
//============================================================================
//^CCaught signal SIGINT
