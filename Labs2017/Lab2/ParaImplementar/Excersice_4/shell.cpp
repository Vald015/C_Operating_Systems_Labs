/*
 *	Author: Osvaldo A. Ramirez
 *  ICOM5007 - Laboratorio 2
 *  Excersice: Interfaz de linea de comandos de usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

void readLine(char *line);
void executeLine(char *line);
void parseLine(char *line, char **argv);
void help();

int main(void){

	char line[1024];							/* User input array */
	char *argv[64];								/* argv array */
	char history[1024][1024];			/* Process history array */
	int counter = 0;			/* Process history counter */
	int pid;											/* Process ID */

	while(1){
		printf("Shell-> ");
		readLine(line);						/* reads user input */
		strcpy(history[counter], line);		/* adds user input to history */
	  counter++;			/* increment user input */
		parseLine(line, argv);	/* parse user input */
		if(strcmp(argv[0], "exit") == 0){			/* user input equals exit, exit program */
			exit(0);
		}else if(strcmp(argv[0], "help") == 0){	/* user input equals help call help function */
			help();
		}else if(strcmp(argv[0], "history") == 0){	/* user input equals history */
			int i; 		/* initializa counter */
			if(argv[1] != NULL){
				if(strcmp(history[atoi(argv[1])-1], "help") == 0)		/* checks if value entered with history equals help command */
					help();		/* call exit function */
					else if(strcmp(history[atoi(argv[1])-1], "exit") == 0)	/* checks if value entered with history equals exit command */
						exit(0);		/*  */
						else if(strcmp(history[atoi(argv[1])-1], "history") == 0) {	/* checks if value entered with history equals history command */
							for(i = 0; i < counter; i++){		/* print all the history items */
								printf(" %d   %s\n", i + 1, history[i]);
							}
						}else executeLine(history[atoi(argv[1])-1]);	/* if its a different command execute that command */
			}else{
				for(i = 0; i < counter; i++){		/* print all the history items */
					printf(" %d   %s\n", i + 1, history[i]);
				}
			}
		}else if(strcmp(argv[0], "cd") == 0){/* user input equals cd */
			if(argv[1] != NULL){
				chdir(argv[1]);			/* change directory to the value of argv[1] entered by the user */
			}
		}else{      /* Execute program from the OS shell */
			char filename[1024] = "/bin/";
			strcat(filename, argv[0]);
			pid = fork();
			if(pid == 0){
				execv(filename, argv);      /* Child executes command */
			}else{
				wait(&pid);     /* Parent wait for child */
			}
		}
	}
	return 0;
}
/*
 * 	The function readLine reads a string of characters given by the user
 */
void readLine(char *line){
	gets(line);
}
/*
 *	The function parseLine depending on what exec function is going to be utilized,
 *  moves the user given line to the argv array
 */
void parseLine(char *line, char **argv){
	while (*line != '\0') {
        while (*line == '\t' || *line == '\n' || *line == ' ')
            *line++ = '\0';
        *argv++ = line;
        while (*line != '\0' && *line != ' ' && *line != '\t' && *line != '\n')
            line++;
     }
}
/*
 *  The function executeLine created a child process which invokes a function of the exec
 *  family to execute the user entered command. The parent must wait until the child terminate.
 */
void executeLine(char *line){
	system(line);
}
/*
 *	 The function help shows a message of how to use the interface.
 */
void help(){
	//printf("This is a simple shell.\n");
	printf("Functions supported by Command Line:\n");
	printf("-history: shows command line history\n-help: shows all the commands supported by th command line\n-cd: change directory\n-exit: exit command line\n");
}
