/*
============================================================================
Name : 32b.c
Author : Rishika Gupta
Date: 20/9/24
32. Write a program to implement semaphore to protect any critical section
.b. protect shared memory from concurrent write access/*
*/
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <string.h>  
#include <unistd.h>  
#include <semaphore.h>
#include <fcntl.h>   
#include <sys/stat.h>

#define SHM_SIZE 256 

int main() {
    
    key_t key = ftok("/tmp", 'Z');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

   
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    
    char *shared_data = (char *)shmat(shmid, (void *)0, 0);
    if (shared_data == (char *)(-1)) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    
    sem_t *sem = sem_open("/sem_shared_mem", O_CREAT, 0644, 1);
    printf("Trying to enter CS\n");

    
    sem_wait(sem);
    printf("Inside critical section, writing to shared memory...\n");

    strcpy(shared_data, "Hello, Shared Memory!");
  printf("Shared memory contains: %s\n", shared_data);


	printf("press enter to leave CS\n");
getchar();
    printf("Leaving critical section\n");
    sem_post(sem); 
    shmdt(shared_data);           
    shmctl(shmid, IPC_RMID, NULL); 
    sem_close(sem);                
    sem_unlink("/sem_shared_mem"); 

    printf("Finished\n");
    return 0;
}
//============================================================================
/*Trying to enter CS
Inside critical section, writing to shared memory...
Shared memory contains: Hello, Shared Memory!
press enter to leave CS

Leaving critical section
Finished
*/
