/*
============================================================================
Name : 8f.c
Author : Rishika Gupta
Date: 18/9/24
8. Write a separate program using signal system call to catch the following signals.
//f. SIGVTALRM (use setitimer system call)
*/
//============================================================================
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void handle_valarm(int signal) {
    printf("Caught SIGVTALRM (Virtual Timer Alarm)\n");
}

int main() {
    struct itimerval t1;

    
    signal(SIGVTALRM, handle_valarm);

    
    t1.it_value.tv_sec = 1;        
    t1.it_value.tv_usec = 0;       
    t1.it_interval.tv_sec = 0;    
    t1.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &t1, NULL); 

    printf("Set the timer\n");


   // for (volatile int i = 0; i < 500000000; ++i) {
     //     }

   while(1);
    

    return 0;
}
//============================================================================
/*Virtual timer set for 1 second of CPU time...
Caught SIGVTALRM (Virtual Timer Alarm)
*/
