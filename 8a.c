/*8. Write a separate program using signal system call to catch the following signals.
a. SIGSEGV*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>


void handle_error(int signal) {
    printf("Caught SIGSEGV (Segmentation Fault)\n");
    exit(1);
}

int main() {

    signal(SIGSEGV, handle_error);   

  // int arr[3];
  // arr[3] = 5;


     int *ptr = NULL; *ptr = 42;

return 0;
}

//Caught SIGSEGV (Segmentation Fault)

