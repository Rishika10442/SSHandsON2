/*17. Write a program to execute ls -l | wc.
b. use dup2*/


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
        dup2(pipefdes[1], STDOUT_FILENO);

        close(pipefdes[0]); 
        close(pipefdes[1]); 
        execlp("ls", "ls", "-l", NULL);
    }

    
    pid2 = fork();
     (pid2 == -1);
    if (pid2 == 0) {
         dup2(pipefdes[0], STDIN_FILENO);

        
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
//     35     308    2260

