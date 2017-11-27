/*
 *  Author: Osvaldo A. Ramirez
 *	ICOM5007 - Laboratory work
 *	LAb1 - Excersice 4: Handling signals
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

pid_t pid;
key_t MyKey;
int   ShmID;
pid_t *ShmPTR;
char  line[100], c;
int   i;

void * signal_handler(int signumber)
{
  if(signumber == SIGINT){
    printf("\nTermination Signal Handled!!\n\n");
    kill(pid, SIGINT);
    //printf("Sent a SIGINT signal\n");
  }else if(signumber == SIGQUIT){
    printf("\nReceived SIGQUIT\n");
    //printf("About to send a SIGQUIT signal\n");
    kill(pid, SIGQUIT);
  }
}

int  main(void)
{
     MyKey   = ftok(".", 's');
     ShmID   = shmget(MyKey, sizeof(pid_t), 0666);
     ShmPTR  = (pid_t *) shmat(ShmID, NULL, 0);
     pid     = *ShmPTR;
     shmdt(ShmPTR);

     while (1) {
          if(signal( SIGINT, (void (*)(int))  signal_handler ) == SIG_ERR){
            printf("\nCouldn't catch SIGINT");
          }else if(signal( SIGQUIT, (void (*)(int))  signal_handler ) == SIG_ERR){
            printf("\nCouldn't catch SIGQUIT");
          }
     }
     return 0;
}
