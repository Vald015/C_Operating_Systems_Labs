#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

void * SIGINT_Handler(int sigNumber){
	printf("\nSIGINT signal handled.\n");
	return 0;
}
void * SIGQUIT_Handler(int sigNumber){
	printf("\nSIGQUIT signal handled.\n");
	return 0;
}

void * SIGTERM_Handler(int sigNumber){
	printf("\nSIGTERM signal handled.\n");
	return 0;
}

void * SIGFPE_Handler(int sigNumber){
	printf("\nSIGFPE signal handled.\n");
	return 0;
}

void * SIGSEGV_Handler(int sigNumber){
	printf("\nSIGSEGV signal handled.\n");
	return 0;
}

void * SIGILL_Handler(int sigNumber){
	printf("\nSIGILL signal handled.\n");
	exit(0);
}

int main(void){

	if(signal( SIGINT, (void (*)(int))  SIGINT_Handler ) == SIG_ERR){
    printf("\nCouldn't catch SIGINT");
  }else if(signal( SIGQUIT, (void (*)(int))  SIGQUIT_Handler ) == SIG_ERR){
    printf("\nCouldn't catch SIGQUIT");
  }else if(signal( SIGTERM, (void (*)(int))  SIGTERM_Handler ) == SIG_ERR){
    printf("\nCouldn't catch SIGTERM");
  }else if(signal( SIGFPE, (void (*)(int))  SIGFPE_Handler ) == SIG_ERR){
    printf("\nCouldn't catch SIGFPE");
  }else if(signal( SIGSEGV, (void (*)(int))  SIGSEGV_Handler ) == SIG_ERR){
    printf("\nCouldn't catch SIGSEGV");
  }else if(signal( SIGILL, (void (*)(int))  SIGILL_Handler ) == SIG_ERR){
    printf("\nCouldn't catch SIGILL");
  }

	//int T = 1;
	//Change to 1 for SIGFPE
	//int wantFPE = 0;
	//int total, zero = 0;

	//Change to 1 for SIGSEGV
	//int wantSEGV = 0;
	//int array[3] = {0, 1, 2};
	//int *pointer;

	//Change to 1 for SIGILL
	//int wantILL = 0;

	//int temp = 0;
	//printf("Enter 1 for FPE, 2 for SEGV: ");
	//scanf("%d", &temp);

	//if(temp==1) wantFPE = 1;
	//if(temp==2) wantSEGV = 1;
	//if(temp==3) wantILL = 1;

	//while(T){
		//printf("Ready.\n");
		//sleep(1);

		//if(wantFPE == 1){
		//	total = 3 / zero;
		//	T = 0;
		//}

		//if(wantSEGV == 1){
		//	array[0] = pointer[1000];
		//	T = 0;
		//}
    //while(1);
    raise(SIGILL);
    //while(1);

	return 0;
}
