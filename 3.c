/*
============================================================================
Name : 3.c
Author : Rishika Gupta
Date: 18/9/24
3. Write a program to set (any one) system resource limit. Use setrlimit system call.*/
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

void get_limits(int res, const char *n) {
    struct rlimit limit;

   
    if (getrlimit(res, &limit) == 0) {
        printf("%s:\n", n);
        printf("  Soft limit: %ld\n", (long)limit.rlim_cur);
        printf("  Hard limit: %ld\n", (long)limit.rlim_max);
    } else {
        perror("getrlimit");
    }
}

int main() {
    struct rlimit limit;

   
    get_limits(RLIMIT_NOFILE, "Limit on number of open files");

    
    limit.rlim_cur = 512;  
    limit.rlim_max = 1024;

    setrlimit(RLIMIT_NOFILE, &limit);

    
    get_limits(RLIMIT_NOFILE, "After changing,limit on number of open files");

    return 0;
}
//============================================================================
/*Limit on number of open files:
  Soft limit: 1024
  Hard limit: 1048576
After changing,limit on number of open files:
  Soft limit: 512
  Hard limit: 1024
*/
