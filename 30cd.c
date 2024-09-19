/*30. Write a program to create a shared memory.
c. detach the shared memory
d. remove the shared memory*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
    key_t key;
    int shmid;
    char *shm;

    
    key = ftok("/tmp", 'D');
    
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    
    printf("Shared memory segment created with ID: %d\n", shmid);

   
    shm = (char *)shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    printf("Attached to shared memory segment.\n");

   
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }
    printf("Detached from shared memory segment.\n");

   if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl (IPC_RMID)");
        exit(EXIT_FAILURE);
    }

    printf("Shared memory removed successfully.\n");

    return 0;
}
/*Shared memory segment created with ID: 32785
Attached to shared memory segment.
Detached from shared memory segment.
Shared memory removed successfully.*/
