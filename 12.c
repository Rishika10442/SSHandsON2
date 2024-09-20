/*
============================================================================
Name : 12.c
Author : Rishika Gupta
Date: 19/9/24
12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.*/
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();  

    if (pid == 0) {
        
        printf("Child process %d\n", getpid());
        printf("Sending SIGKILL to parent %d \n", getppid());
        kill(getppid(), SIGKILL);

        
       sleep(5);

        printf("Child process %d is now orphan, parent pid is %d\n", getpid(),getppid());

        
     
    } else {
     
        printf("Parent  %d is alive. Waiting for signal from child...\n", getpid());
        sleep(10); 
    }

    return 0;
}
//============================================================================
/*Parent  5735 is alive. Waiting for signal from child...
Child process 5736
Sending SIGKILL to parent 5735 
Killed
Child process 5736 is now orphan, parent pid is 1740
*/
