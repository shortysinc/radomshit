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
Aparecen mensajes repetidos porque la orden printf, la que hay dentro del
bucle, la ejecuta cada proceso hijo una primera vez tras ser creado como
resultado de la llamada al sistema fork que hay justo en la linea anterior del
printf, y una segunda vez en la siguiente iteraci´on del bucle (excepto en el
caso de encontrarse en su ultima iteracion).

Se observa que los procesos terminan en el orden contrario al que se han
creado, es decir, primero termina el ultimo proceso creado y el ultimo proceso
en terminar es el inicial. Esto ocurre gracias a la llamada al sistema wait
que cambia el estado del proceso padre a bloqueado hasta que el proceso hijo
termine.
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {
	int num;
	pid_t pid;
	for (num= 0; num< 3; num++)
	{
		pid= fork();
		printf ("Soy el proceso de PID %d y mi padre tiene %d de PID.\n",getpid(),getppid());

		if (pid!= 0)
			break;
		srandom(getpid());
		sleep (random()%3);
	}
	if (pid!= 0)
		printf ("Fin del proceso de PID %d.\n", wait (NULL));
	return 0;
}
