/*
 *  Author: Osvaldo A. Ramirez
 *	ICOM5007 - Laboratory work
 *	LAb1 - Excersice 4: Handling signals
 */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void * signal_handler(int signumber)
{
  if(signumber == SIGINT){
    printf("\nHandled SIGINT\n");
  }else if(signumber == SIGQUIT){
    printf("\nHandled SIGQUIT\n");
  }else if(signumber == SIGTERM){
    printf("\nHandled SIGTERM\n");
  }else if(signumber == SIGFPE){
    printf("\nHandled SIGFPE\n");
  }else if(signumber == SIGSEGV){
    printf("\nHandled SIGSEGV\n");
  }else if(signumber == SIGILL){
    printf("\nHandled SIGILL\n");
  }
}

int main()
{
  if(signal( SIGINT, (void (*)(int))  signal_handler ) == SIG_ERR){
    printf("\nCouldn't catch SIGINT");
  }else if(signal( SIGQUIT, (void (*)(int))  signal_handler ) == SIG_ERR){
    printf("\nCouldn't catch SIGQUIT");
  }else if(signal( SIGTERM, (void (*)(int))  signal_handler ) == SIG_ERR){
    printf("\nCouldn't catch SIGTERM");
  }else if(signal( SIGFPE, (void (*)(int))  signal_handler ) == SIG_ERR){
    printf("\nCouldn't catch SIGFPE");
  }else if(signal( SIGSEGV, (void (*)(int))  signal_handler ) == SIG_ERR){
    printf("\nCouldn't catch SIGSEGV");
  }else if(signal( SIGILL, (void (*)(int))  signal_handler ) == SIG_ERR){
    printf("\nCouldn't catch SIGILL");
  }

  while(1) {
    printf("Doing Nothing...\n");
    sleep(1000);
  }
}
