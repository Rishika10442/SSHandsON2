//
/*============================================================================
Name : 15.c
Author : Rishika Gupta
Date: 19/9/24
15. Write a simple program to send some data from parent to the child process.
//============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    char w[] = "Hello child!";
    char r[100];
    pid_t pid;

   pipe(pipefd);
    pid = fork();

   

    if (pid > 0) {
   	printf("parent is writing to child\n");
        close(pipefd[0]);
        write(pipefd[1], w, strlen(w) + 1);
        close(pipefd[1]);
    } else {
        close(pipefd[1]);
        
        read(pipefd[0], r, sizeof(r));
        printf("Child process: %s\n", r);

        close(pipefd[0]);
    }

    return 0;
}
//============================================================================
//parent is writing to child
//Child process: Hello child!

