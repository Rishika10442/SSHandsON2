/*23. Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <errno.h>

#define PIPE_PATH "my_pipe"

void print_maxfiles() {
    struct rlimit rl;
    
    getrlimit(RLIMIT_NOFILE, &rl);

    printf("Maximum number of open files: %ld\n", rl.rlim_cur);
}

void print_pipesize() {
    int fd;
    size_t buffer_size;
	int pipefd[2];
   
      
#ifdef F_GETPIPE_SZ
    buffer_size = fcntl(pipefd[0],F_GETPIPE_SZ);
#endif
      printf("Size of the pipe buffer: %zu bytes\n", buffer_size);

   close(pipefd[0]);
close(pipefd[1]);
}

int main() {
    print_maxfiles();
    print_pipesize();
    return 0;
}

/*Maximum number of open files: 1024
Size of the pipe buffer: 1048576 bytes
*/
