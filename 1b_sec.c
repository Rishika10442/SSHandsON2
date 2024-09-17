/*Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_VIRTUAL*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>


void handler(int signum) {
    printf("Timer expired!Signal is caught Exiting program...\n");
    _exit(0); 
}

int main() {
    struct itimerval timer;
    
   
    signal(SIGVTALRM, handler);
    
   
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 0;
    
   
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    
       setitimer(ITIMER_VIRTUAL, &timer, NULL);
    
   
    while (1);
    
    return 0;
}

//Timer expired!Signal is caught Exiting program...


