/*
 ============================================================================
 Name        : Ej1.c
 Author      : JS
 Version     :
 Copyright   : 
 Description : Observa el siguiente codigo y escribe la jerarquia de procesos
 	 	 	   resultante.
 ============================================================================
 */
/*
Se observa que el proceso padre es siempre el ultimo en terminar. Esto es
debido a que la llamada al sistema wait, que hace que el proceso padre pase
a estado bloqueado hasta que un proceso hijo termine, se encuentra dentro de
un bucle que va a hacer que se llame tantas veces como procesos hijos creo.

Sin embargo, los procesos hijos acaban en cualquier orden dependiendo del
retardo que cada uno realice con la orden sleep.
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
	int num;
	pid_t pid;
	srandom(getpid());
	for (num= 0; num< 3; num++)
	{
		pid= fork();
		printf ("Soy el proceso de PID %d y mi padre tiene %d de PID.\n",getpid(),getppid());
		if (pid== 0)
			break;
	}
	if (pid== 0)
		sleep(random() %5);
	else
		for (num= 0; num< 3; num++)
			printf ("Fin del proceso de PID %d.\n", wait (NULL));
	return 0;
}
