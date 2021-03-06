#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>


int  main(void)
{
     pid_t pid;
     key_t MyKey;
     int   ShmID;
     pid_t *ShmPTR;
     char  line[100], c;
     int   i;

     MyKey   = ftok(".", 's');
     ShmID   = shmget(MyKey, sizeof(pid_t), 0666);
     ShmPTR  = (pid_t *) shmat(ShmID, NULL, 0);
     pid     = *ShmPTR;
     shmdt(ShmPTR);

     while (1) {
          printf("Want to interrupt the other guy or kill it or terminate (i or k or t)? ");
          gets(line);
          for (i = 0; !(isalpha(line[i])); i++);
               c = line[i];
          if (c == 'i' || c == 'I') {
               kill(pid, SIGINT);
               printf("Sent a SIGINT signal\n");
          }
          else if (c == 'k' || c == 'K') {
               printf("About to send a SIGQUIT signal\n");
               kill(pid, SIGQUIT);
               printf("Done.....\n");
               exit(0);
          }else if(c == 't'|| c == 'T'){
              //printf("About to sent a SIGTERM signal\n");
              kill(pid,SIGTERM);
              //printf("SENT SIGTERM signal");
              exit(0);
          }
          else
               printf("Wrong keypress (%c).  Try again\n", c);
     }
     return 0;
}
