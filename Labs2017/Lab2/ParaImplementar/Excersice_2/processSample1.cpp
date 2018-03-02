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
    printf("\nChild process ID: %d\n",getpid());
    printf("Child parent process ID: %d\n",getppid());
    printf("I am the child, return from fork=%d\n", pid);
    printf("Still around...\n\n");
    system("ps -a");
  }else { /* parent process */
    wait(NULL);   /*  */
    printf("\nParent ID of the parent process: %d\n",getppid());
	  printf("I am the parent, return from fork, child pid=%d\n", pid);
	  printf("Parent exiting!\n\n");
    printf("** System 'ps -a' is called in the child to be able to identify the child. **\n\n");

    //system("ps -a");
	  exit(0);
  }

}
