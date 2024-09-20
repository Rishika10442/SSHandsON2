/*
============================================================================
Name : 32a.c
Author : Rishika Gupta
Date: 20/9/24
32. Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore*/
//============================================================================
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    struct {
        int t_no;
    } db;
    sem_t *sem;
    int fd;


    sem = sem_open("/ticket_sem", O_CREAT, 0644, 1);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    
    fd = open("db", O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    
    read(fd, &db, sizeof(db));

    
    printf("Before entering CS\n");
    sem_wait(sem); 
    
 
    printf("Current ticket number: %d\n", db.t_no);
    db.t_no++;
    lseek(fd, 0L, SEEK_SET);
    printf("Inside CS\n");
    write(fd, &db, sizeof(db));
    printf("Your ticket number is %d\n", db.t_no);

 
    printf("Press Enter to leave CS");
    getchar();

 
    printf("Unlocked and leaving\n");
    sem_post(sem);
    
   
    sem_close(sem);
    sem_unlink("/ticket_sem"); 
    close(fd);
    
    printf("Finished\n");
    return 0;
}
//============================================================================
/*Before entering CS
Current ticket number: 15
Inside CS
Your ticket number is 16
Press Enter to leave CS
Unlocked and leaving
Finished*/
