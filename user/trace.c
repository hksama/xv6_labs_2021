#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

// Implementing the system call tracing lab. Link is https://pdos.csail.mit.edu/6.828/2021/labs/syscall.html
// It should take one argument, an integer "mask", whose bits specify 
//which system calls to trace.
// For example, to trace the fork system call, a program calls trace(1 << SYS_fork),
// where SYS_fork is a syscall number from kernel/syscall.h.
// The line should contain the process id, the name of the system call and the
// return value; you don't need to print the system call arguments. The 
// trace system call should enable tracing for the process that calls it and any children that it subsequently forks, 
//but should not affect other processes.

int
main(int argc, char *argv[])
{
  int mask;
  char *nargv[MAXARG]; //max no of executable args allowed excluding syscall mask.


  // Check if the number of arguments is less than 3 or if the first argument is not a digit
  if(argc < 3 || (argv[1][0] < '0' || argv[1][0] > '9')){
    fprintf(2, "Usage: %s mask command\n", argv[0]);
    exit(1);
  }

  if (trace(atoi(argv[1])) < 0) {
    fprintf(2, "%s: trace failed\n", argv[0]);
    exit(1);
  }
  mask = argv[1];
  //writing the syscall arguments to nargv array to pass it to exec system call.
  // We are starting nargv from index 2 because index 0 is the syscall name and 
  // all others are the arguments for the syscall.
  for(int i = 2; i < argc && i < MAXARG; i++){
    nargv[i-2] = argv[i];
  }

  //check syscall value
  

  exec(nargv[0], nargv);
  exit(0);
}
