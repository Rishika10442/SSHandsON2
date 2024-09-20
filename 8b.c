/*
============================================================================
Name : 8b.c
Author : Rishika Gupta
Date: 18/9/24
8. Write a separate program using signal system call to catch the following signals.
b. SIGINT*/
//============================================================================
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handle_error(int signal) {
    printf("Caught SIGINT (Interrupt from keyboard)\n");
    exit(0);
}

int main() {
signal(SIGINT, handle_error);   

while (1) {
        sleep(1); 
}
return 0;
}
//============================================================================
//Caught SIGINT (Interrupt from keyboard)
