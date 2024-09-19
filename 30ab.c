/*30. Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
 */

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
    char *data;
    struct shmid_ds shm_desc;
	int status;

    key = ftok("/tmp", 'C');
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

    shm = (char *)shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

   strcpy(shm, "Writing to Shared Memory!");
    printf("Data written to shared memory\n");

    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    shm = (char *)shmat(shmid, NULL, SHM_RDONLY);
    if (shm == (char *)-1) {
        perror("shmat (SHM_RDONLY)");
        exit(EXIT_FAILURE);
 }

printf("Trying to overwrite shared memory...\n");
    status = snprintf(shm, SHM_SIZE, "New Data");
    if (status < 0) {
        perror("snprintf");
        printf("Failed to write to shared memory. It is likely in read-only mode.\n");
    } else {
        printf("Data written to shared memory: %s\n", shm);
    }
    
  
    return 0;
}
/*Data written to shared memory
Trying to overwrite shared memory...
Segmentation fault (core dumped)
*/
