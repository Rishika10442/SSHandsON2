/*9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void reset(int signum) {
   printf("\ninside reset handler, next CTRL C will cause interrupt as default behaviour\n");
    signal(SIGINT, SIG_DFL);
}

int main() {
    
    signal(SIGINT, SIG_IGN);
    printf("Ignoring SIGINT\n");

    printf("going to sleep , SIGINT wont work now\n"); 
    sleep(5);

    
    signal(SIGINT, reset);
    printf("\nSIGINT can now be reset\n");

    
    while(1) {
        pause();  
    }

    return 0;
}

/*Ignoring SIGINT
going to sleep , SIGINT wont work now
^C^C
SIGINT can now be reset
^C
inside reset handler, next CTRL C will cause interrupt as default behaviour
^C
*/
