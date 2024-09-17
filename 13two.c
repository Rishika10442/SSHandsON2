/*13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    pid_t pid;
    
    printf("Enter the PID of the process to send SIGSTOP: ");
    scanf("%d", &pid);

   
    if (kill(pid, SIGSTOP) == 0) {
        printf("SIGSTOP signal sent to process %d\n", pid);
    } else {
        perror("Failed to send SIGSTOP");
        exit(EXIT_FAILURE);
    }

   
    return 0;
}

/*Enter the PID of the process to send SIGSTOP: 4478
SIGSTOP signal sent to process 4478
*/
