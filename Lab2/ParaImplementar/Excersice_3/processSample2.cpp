/*
 *  Author: Osvaldo A. Ramirez
 *	ICOM5007 - Laboratory work
 *	Lab 2
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

  int pid;
  pid = fork();

  if (pid < 0) { /* error occurred */
	  fprintf(stderr, "Fork failed!\n");
	  exit(-1);
  }else if (pid == 0) { /* child process */
    printf("\nI am the child, return from fork=%d\n\n", pid);
    //wait(NULL);
    execl("/bin/ls","-l",NULL);
    //wait(NULL);
    printf("\nStill around...\n");
  }else { /* parent process */
    wait(NULL);
	  printf("\nI am the parent, return from fork, child pid=%d\n", pid);
	  printf("Parent exiting!\n\n");
	  exit(0);
  }
}
