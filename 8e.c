/*Write a separate program using signal system call to catch the following signals.
e. SIGALRM (use setitimer system call)
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
void handle_alarmError(int signal) {
    printf("Caught SIGALRM (Alarm Signal)\n");
}

int main(){
    struct itimerval t1;
    t1.it_value.tv_sec = 2;
    t1.it_value.tv_usec = 0;
    t1.it_interval.tv_sec = 0;
    t1.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &t1, NULL);
	signal(SIGALRM, handle_alarmError);


    pause(); 
 

return 0;
}
//Caught SIGALRM (Alarm Signal)

