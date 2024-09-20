/*
============================================================================
Name : 2.c
Author : Rishika Gupta
Date: 18/9/24
Write a program to print the system resource limits. Use getrlimit
Name-2.c
============================================================================
*/

#include <stdio.h>
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
    get_limits(RLIMIT_CPU, "CPU time");
    get_limits(RLIMIT_FSIZE, "File size");
    get_limits(RLIMIT_DATA, "Data segment size");
    get_limits(RLIMIT_STACK, "Stack size");
    get_limits(RLIMIT_CORE, "Core file size");
    get_limits(RLIMIT_RSS, "Resident set size");
    get_limits(RLIMIT_NPROC, "Number of processes");
    get_limits(RLIMIT_NOFILE, "Number of open files");
    get_limits(RLIMIT_MEMLOCK, "Locked memory");
    get_limits(RLIMIT_AS, "Address space");
    get_limits(RLIMIT_LOCKS, "File locks");

    return 0;
}
//============================================================================
/*CPU time:
  Soft limit: -1
  Hard limit: -1
File size:
  Soft limit: -1
  Hard limit: -1
Data segment size:
  Soft limit: -1
  Hard limit: -1
Stack size:
  Soft limit: 8388608
  Hard limit: -1
Core file size:
  Soft limit: 0
  Hard limit: -1
Resident set size:
  Soft limit: -1
  Hard limit: -1
Number of processes:
  Soft limit: 30799
  Hard limit: 30799
Number of open files:
  Soft limit: 1024
  Hard limit: 1048576
Locked memory:
  Soft limit: 1018818560
  Hard limit: 1018818560
Address space:
  Soft limit: -1
  Hard limit: -1
File locks:
  Soft limit: -1
  Hard limit: -1
*/
