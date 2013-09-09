/*
 ============================================================================
 Name        : EjemploThreads3.c
 Author      : Jorge Shortys
 Version     :
 Copyright   : 
 ============================================================================
 */

#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
/*programa que temporiza la ejecución de un proceso hijo */
pid_t pid;
void tratar_alarma(void){ kill(pid, SIGKILL); }
main(int argc, char **argv) {
	int status;
	char **argumentos;
	struct sigaction act;
	argumentos = &argv[1];
	pid = fork();
	switch(pid) {
	case -1: /* error del fork() */
	perror ("fork");exit(-1);
	case 0: /* proceso hijo */
		execvp(argumentos[0], argumentos);
		perror("exec"); exit(-1);
	default: /* padre */
		/* establece el manejador */
		act.sa_handler = tratar_alarma;
		/*ninguna acción específica */
		act.sa_flags = 0;
		sigaction(SIGALRM, &act, NULL);
		alarm(5);
		wait(&status);
	}
	exit(0);
}
