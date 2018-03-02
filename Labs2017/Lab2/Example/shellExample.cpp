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
	int history_counter = 0;			/* Process history counter */
	int pid;											/* Process ID */

	while(1){
		printf("Shell-> ");
		readLine(line);						/* reads user input */
		strcpy(history[history_counter], line);		/* adds user input to history */
		history_counter++;			/* increment user input */
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
							for(i = 0; i < history_counter; i++){		/* print all the history items */
								printf(" %d   %s\n", i + 1, history[i]);
							}
						}else executeLine(history[atoi(argv[1])-1]);	/* if its a different command execute that command */
			}else{
				for(i = 0; i < history_counter; i++){		/* print all the history items */
					printf(" %d   %s\n", i + 1, history[i]);
				}
			}
		}else if(strcmp(argv[0], "cd") == 0){/* user input equals cd */
			if(argv[1] != NULL){
				chdir(argv[1]);			/* change directory to the value of argv[1] entered by the user */
			}
		}else{
			printf("command not supported\n");
			//char filename[1024] = "/bin/";
			//strcat(filename, argv[0]);
			//pid = fork();
			//if(pid == 0){
			//	execv(filename, argv);
			//}else{
			//	wait(&pid);
			//}
		}
	}
	return 0;
}
/*
 * 	La funcion readLine lee una línea de caracteres ingresadas por el usuario y la escribe en la
 * 	variable line.
 */
void readLine(char *line){
	gets(line);
}
/*
 *	La funcion parseLine dependiendo de qué función de la familia exec desee utilizar, podrá ser
 * 	necesario que mueva la línea ingresada por el usuario a un array de cadenas.
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
 *	La funcion executeLine crea un child process en el cual invoca a una función de la
 * 	familia exec para ejecutar el comando ingresado por el usuario. El parent process debe
 * 	esperara la terminación del child para continuar
 */
void executeLine(char *line){
	system(line);
}
/*
 *	Muestra un mensaje al usuario acerca de cómo utilizar la interfaz.
 */
void help(){
	//printf("This is a simple shell.\n");
	printf("Some functions that can be run:\n");
	printf("\t-history\n\t-help\n\t-cd\n\t-exit\n");
}
