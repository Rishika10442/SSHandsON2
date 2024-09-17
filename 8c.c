/*8. Write a separate program using signal system call to catch the following signals.

c. SIGFPE*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handle_error(int signal) {
    printf("Caught SIGFPE (Floating Point Exception)\n");
    exit(1);
}

int main() {

signal(SIGFPE, handle_error); 
int x = 2 / 0;
return 0;
}
 
//Caught SIGFPE (Floating Point Exception)

