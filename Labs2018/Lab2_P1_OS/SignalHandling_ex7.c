/* Sample program to handle system signals */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void * signal_handler(int signumber)
{
  switch(signumber){

    case SIGINT:
      printf("\nSIGINT Signal Handled!!\n\n");
      break;

    case SIGQUIT:
      printf("\nSIGQUIT signal handled!\n\n");
      break;

    case SIGTERM:
      printf("\n SIGTERM signal handled!\n\n");
      break;

    case SIGFPE:
      printf("\nSIGFPE signal handled!\n\n");
      exit(1);
      break;

    case SIGSEGV:
      printf("\nSIGSEGV signal handled!\n\n");
      exit(1);
      break;

    case SIGILL:
      printf("SIGILL signal handled!\n\n");
      break;

    default:
      printf("\nNo Signal handled!!\n\n");

  }
}

int main(){

  signal(SIGINT, (void *) signal_handler);
  signal(SIGQUIT, (void *) signal_handler);
  signal(SIGTERM, (void *) signal_handler);
  signal(SIGFPE, (void *) signal_handler);
  signal(SIGSEGV, (void *) signal_handler);
  signal(SIGILL, (void *) signal_handler);

  // while(1)
  // {
    printf("Enter 1 for SIGFPE Error, 2  for SIGSEGV\n");

    int num = 0;
    scanf("%d", &num);

    if(num == 1) {
      //printf("\ncreate SIGFPE\n\n");
      int zero = 0;
      int temp = 3/zero;
    } else if(num == 2) {
      // printf("\ncreate SIGSEGV\n\n");
      int *p = NULL;
      *p = 1;
    }
    else {
      printf("\nWrong input\n");
    }
    printf("Doing Nothing ... \n");
    //sleep(1000);
  //}
}
