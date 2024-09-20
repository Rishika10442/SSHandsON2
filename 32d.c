/*
============================================================================
Name : 32d.c
Author : Rishika Gupta
Date: 20/9/24*/

//32d. remove the created semaphore
//============================================================================
#include<stdio.h>
#include<sys/sem.h>
#include<unistd.h>
union semun {
int val;
struct semid_ds *buff;
unsigned short int *array;
};

int main(void)
{
union semun arg;
int key , sid;
key = ftok("/tmp",'X');
sid=semget(key,1,0);
semctl(sid, 0, IPC_RMID);
printf("Semaphore removed successfully.\n");
}
//============================================================================
//Semaphore removed successfully.

