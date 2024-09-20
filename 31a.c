/*31. Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore*/

#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h> 
#include <stdlib.h> 

int main() {
    sem_t *s;

   
    s = sem_open("/binary_semaphore", O_CREAT, 0644, 1);

    printf("Semaphore created and initialized to 1.\n");
    printf("Waiting to enter critical section...\n");
    sem_wait(s);  
    printf("Entered critical section.\n");

    
    sleep(5);

   
    printf("Exiting critical section.\n");
    sem_post(s);

    
    sem_close(s);

   
    sem_unlink("/binary_semaphore");

    return 0;
}

/*Semaphore created and initialized to 1.
Waiting to enter critical section...
Entered critical section.
Exiting critical section.
*/
