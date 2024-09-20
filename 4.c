/*
============================================================================
Name : 4.c
Author : Rishika Gupta
Date: 18/9/24
Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter*/
//============================================================================
#include <stdio.h>
#include <unistd.h>


unsigned long long read_tsc() {
    unsigned long long tsc;
    asm volatile ("rdtsc" : "=A"(tsc));
    return tsc;
}

int main() {
    unsigned long long s, e;
    int i;

   
    s = read_tsc();

       for (i = 0; i < 100; i++) {
        getppid();
    }

   
    e = read_tsc();

   
    printf("Time taken for 100 getppid() calls: %llu \n", e - s);

    return 0;
}
//============================================================================
//Time taken for 100 getppid() calls: 618160

