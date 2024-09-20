/*
============================================================================
Name : 11.c
Author : Rishika Gupta
Date: 19/9/24
11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.*/
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void reset(int signum) {
    printf("\nInside reset handler, also will re raise SIGINT\n");

    
    struct sigaction sa_def;
    sa_def.sa_handler = SIG_DFL;  
    sigemptyset(&sa_def.sa_mask);
    sa_def.sa_flags = 0;

    sigaction(SIGINT, &sa_def, NULL);  

    
    raise(SIGINT);
}

int main() {
    struct sigaction sa_ignore, sa_reset;

    
    sa_ignore.sa_handler = SIG_IGN;  
    sigemptyset(&sa_ignore.sa_mask);
    sa_ignore.sa_flags = 0;

    sigaction(SIGINT, &sa_ignore, NULL);  

    printf("Ignoring SIGINT....\n");
    sleep(5);  

  // printf("\n calling reset handler\n");
    sa_reset.sa_handler = reset;  
    sigemptyset(&sa_reset.sa_mask);
    sa_reset.sa_flags = 0;

    sigaction(SIGINT, &sa_reset, NULL); 

    printf("\nSIGINT handler has been reset\n");

    
    while (1) {
        pause();  
    }

    return 0;
}
//============================================================================
/*Ignoring SIGINT....
^C^C^C
SIGINT handler has been reset
^C
Inside reset handler, also will re raise SIGINT
*/
