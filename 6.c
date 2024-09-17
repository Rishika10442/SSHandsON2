/*6. Write a simple program to create three threads.*/



#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void* func(void* arg) {
    int num = *((int*)arg);
    printf("Thread %d is running\n", num);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    int t_args[3];  
    int i;

    
    for (i = 0; i < 3; i++) {
        t_args[i] = i + 1;
        if (pthread_create(&threads[i], NULL, func, &t_args[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

   
    for (i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Threads are finished with execution\n");

    return 0;
}

/*Thread 1 is running
Thread 2 is running
Thread 3 is running
Threads are finished with execution
*/
