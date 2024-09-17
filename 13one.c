/*13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void handleSigstop(int signum) {
    printf(" catch SIGSTOP\n");
}

int main() {
    

    
  
    if (signal(SIGSTOP, handleSigstop) == SIG_ERR) {
        printf("Can't catch SIGSTOP.\n");
    }

    printf("Process PID: %d is running..\n", getpid());
    
    
    while (1) {
        printf("Running...%d\n",getpid());
        sleep(3);
    }

    return 0;
}
/*Can't catch SIGSTOP.
Process PID: 4478 is running..
Running...4478
Running...4478

[2]+  Stopped                 ./a.out
*/
