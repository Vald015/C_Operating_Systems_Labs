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
	//return 0;
	exit(0);
}
void * SIGSEGV_Handler(int sigNumber){
	printf("\nSIGSEGV signal handled.\n");
	exit(0);
	//return 0;
}
void * SIGILL_Handler(int sigNumber){
	printf("\nSIGILL signal handled.\n");
	return 0;
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
	//int FPEsignal = 0;
	int total, zero = 0;
	//int SEGVsignal = 0;
	int array[3] = {0, 1, 2};
	int *pointer;
	int temp = 0;

	//while(T){
	printf("Enter 1 for FPE, 2 for SEGV: ");
	scanf("%d", &temp);
	getchar();

	//if(temp==1) FPEsignal = 1;
	//if(temp==2) SEGVsignal = 1;
	//if(temp==3) wantILL = 1;

	//while(T){
		//printf("Ready.\n");
		sleep(1);

		if(temp == 1){
			total = 3 / zero;
		}
		if(temp == 2){
			array[0] = pointer[1000];
		}
		//total = 0;
		//temp = 0;
	//}

		//if(wantILL == 1){
		//	raise(SIGILL);
		//	T = 0;
		//}

	//}
	return 0;
}
