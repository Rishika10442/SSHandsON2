/*
============================================================================
Name : 31b.c
Author : Rishika Gupta
Date: 20/9/24
31. Write a program to create a semaphore and initialize value to the semaphore.
b. create a counting semaphore*/
//============================================================================
#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <stdlib.h> 

int main() {
    sem_t *s;
    s = sem_open("/cs", O_CREAT, 0644, 2);

    printf("Counting semaphore created , at a time 2 processes can be in CS.\n");

    
    printf("Waiting to enter critical section...\n");
    sem_wait(s);
    printf("Entered critical section.\n");
    sleep(10);
    printf("Exiting critical section.\n");
   sem_post(s);
    sem_close(s);
    sem_unlink("/cs");
    return 0;
}
//============================================================================
/*Counting semaphore created , at a time 2 processes can be in CS.
Waiting to enter critical section...
Entered critical section.
Exiting critical section.*/
