/*
============================================================================
Name : 8d.c
Author : Rishika Gupta
Date: 18/9/24
8. Write a separate program using signal system call to catch the following signals.
d. SIGALRM (use alarm system call)*/
//============================================================================
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

void handle_error(int signal) {
    printf("Caught SIGALRM (Alarm Signal)\n");
}

int main() {

 signal(SIGALRM, handle_error);

alarm(3);
    pause(); 
return 0;
} 
//============================================================================
//Caught SIGALRM (Alarm Signal)

