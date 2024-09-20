/*
============================================================================
Name : 32c.c
Author : Rishika Gupta
Date: 20/9/24
32. Write a program to implement semaphore to protect any critical section.
c. protect multiple pseudo resources ( may be two) using counting semaphore*/
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <semaphore.h>
#include <fcntl.h>  
#include <unistd.h>

#define SHM_SIZE 1024 
int main() {
   
    sem_t *sem = sem_open("/shm_semaphore", O_CREAT, 0644, 2);
   
    key_t key = ftok("/tmp", 'Y');
   
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    

    
    char *smemory = (char *)shmat(shmid, NULL, 0);
    if (smemory == (char *)(-1)) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    printf("trying to access shared memory\n");
    sem_wait(sem);

    
    printf("Writing to shared memory...\n");
    char message[100];
    printf("Enter a message to write to shared memory: ");
    fgets(message, sizeof(message), stdin);
    
    strcat(smemory, message);
    printf("Shared memory now contains: %s\n", smemory);

   
    sem_post(sem);

    
    shmdt(smemory);

    
    sem_close(sem);

    return 0;
}
//============================================================================
/*trying to access shared memory
Writing to shared memory...
Enter a message to write to shared memory: asy
Shared memory now contains: asdf
ds
sda
asy
*/
