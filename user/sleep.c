// Implement a user-level sleep program for xv6, along the lines of the UNIX
// sleep command. Your sleep should pause for a user-specified number of ticks. 
// A tick is a notion of time defined by the xv6 kernel, namely the time 
// between two interrupts from the timer chip. Your solution should be in 
// the file user/sleep.c.

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

// takes an int n which is no of ticks the program sleeps for.
int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Invalid arg length, Expected 1 argument only.");
        //fail
        exit(1);
    }
    // call the syscall sleep
    sleep(atoi(argv[1]));
    exit(0);
}