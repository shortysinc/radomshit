/*
 ============================================================================
 Name        : PruebaFork.c
 Author      : Jorge Shortys
 Version     :
 Copyright   : 
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int varGlobal;
void main() {
	int varLocal=3;
	pid_t pid;
	varGlobal=10;
	printf("Soy el proceso original. Mi PID es %d\n", getpid());
	fflush(NULL);
	pid = fork();
	if (pid ==-1) {
		perror("Error en fork()\n");
		exit(-1);
	}
	if (pid == 0 ) {
		// CODIGO DEL PROCESO HIJO
		varGlobal = varGlobal + 5;
		varLocal = varLocal + 5;
	}
	else {
		// CODIGO DEL PADRE: pid contiene el pid del hijo
		wait(NULL);
		varGlobal = varGlobal + 10;
		varLocal = varLocal + 10;
	}
	printf("Soy el proceso con PID %d. Mi padre es %d Global: %d Local %d\n", getpid(), getppid(),varGlobal, varLocal );
}
