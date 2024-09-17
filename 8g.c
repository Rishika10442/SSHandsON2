//8. Write a separate program using signal system call to catch the following signals
//g. SIGPROF (use setitimer system call)
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void handle_sigprof(int signal) {
    printf("Caught SIGPROF (Profiling Timer Alarm)\n");
}

int main() {
    struct itimerval t1;

   
    signal(SIGPROF, handle_sigprof);

   
    t1.it_value.tv_sec = 1;     
    t1.it_value.tv_usec = 0;    
    t1.it_interval.tv_sec = 0;  
    t1.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &t1, NULL); 

    printf("timer is set\n");

    
    for (volatile int i = 0; i < 1000000000; ++i) {
    
    }
    printf("Sleeping...\n");
    sleep(2); 

//    pause();

    printf("Done\n");

    return 0;
}
/*timer is set
Caught SIGPROF (Profiling Timer Alarm)
Sleeping...
Done*/
