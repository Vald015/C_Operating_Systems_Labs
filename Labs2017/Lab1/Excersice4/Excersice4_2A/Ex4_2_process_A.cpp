/*
 *  Author: Osvaldo A. Ramirez
 *	ICOM5007 - Laboratory work
 *	LAb1 - Excersice 4: Handling signals
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

void SIGINT_handler(int);
void SIGQUIT_handler(int);
void SIGTERM_handler(int);

int ShmID;
pid_t *ShmPTR;

int main(void)
{
     int   i;
     pid_t pid = getpid();
     key_t MyKey;

     if (signal(SIGINT, SIGINT_handler) == SIG_ERR) {
          printf("SIGINT install error\n");
          exit(1);
     }
     if (signal(SIGQUIT, SIGQUIT_handler) == SIG_ERR) {
          printf("SIGQUIT install error\n");
          exit(2);
     }
     if(signal(SIGTERM,SIGTERM_handler) == SIG_ERR){
       printf("SIGQUIT install error\n");
       exit(3);
     }

     MyKey   = ftok(".", 's');
     ShmID   = shmget(MyKey, sizeof(pid_t), IPC_CREAT | 0666);
     ShmPTR  = (pid_t *) shmat(ShmID, NULL, 0);
     *ShmPTR = pid;

     for (i = 0; ; i++) {
          printf("From process %d: %d\n", pid, i);
          sleep(1);
     }
     return 0;
   }

void  SIGINT_handler(int sig)
{
     signal(sig, SIG_IGN);
     printf("From SIGINT: just got a %d (SIGINT ^C) signal\n", sig);
     signal(sig, SIGINT_handler);
}
void  SIGQUIT_handler(int sig)
{
     signal(sig, SIG_IGN);
     printf("From SIGQUIT: just got a %d (SIGQUIT ^\\) signal"
                          " and is about to quit\n", sig);
     shmdt(ShmPTR);
     shmctl(ShmID, IPC_RMID, NULL);

     exit(3);
}
void  SIGTERM_handler(int sig)
{
     signal(sig, SIG_IGN);
     shmdt(ShmPTR);
     shmctl(ShmID, IPC_RMID, NULL);

     exit(3);
}
