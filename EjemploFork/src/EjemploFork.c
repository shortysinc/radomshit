/*
 ============================================================================
 Name        : EjemploFork.c
 Author      : Jorge Shortys
 Version     :
 Copyright   : 
 ============================================================================
 */

#include <sys/types.h>
#include <stdio.h>
/* programa que ejecuta el mandato ls -l */
main() {
	pid_t pid;
	int status;
	pid = fork();
	//printf("pid %d\n",pid);

	if (pid == 0) { /* proceso hijo */
		printf("pid hijo %d\n",pid);

		execlp("ls","ls","-l",NULL);
		exit(-1);
	}
	else /* proceso padre */
		printf("pid padre %d\n",pid);

		while (pid != wait(&status));
	exit(0);
}
