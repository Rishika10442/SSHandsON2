/*5. Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.*/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main() {
    long res;

   
    res = sysconf(_SC_ARG_MAX);
        printf("Maximum length of arguments to exec family of functions: %ld\n", res);
   
    res = sysconf(_SC_CHILD_MAX);
    printf("Maximum number of simultaneous processes per user: %ld\n", res);
   
    res = sysconf(_SC_CLK_TCK);
    printf("Number of clock ticks per second: %ld\n", res);
    
    res = sysconf(_SC_OPEN_MAX);
    printf("Maximum number of open files: %ld\n", res);
   

    
    res = sysconf(_SC_PAGESIZE);
     printf("Size of a page: %ld bytes\n", res);
   
    res = sysconf(_SC_PHYS_PAGES);
    printf("Total number of pages in physical memory: %ld\n", res);
   

    res = sysconf(_SC_AVPHYS_PAGES);
    printf("Number of currently available pages in physical memory: %ld\n", res);
   

    return 0;
}

/*Maximum length of arguments to exec family of functions: 2097152
Maximum number of simultaneous processes per user: 30799
Number of clock ticks per second: 100
Maximum number of open files: 1024
Size of a page: 4096 bytes
Total number of pages in physical memory: 1989880
Number of currently available pages in physical memory: 724132
*/
