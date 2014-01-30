/*
Ejercicio 2. Modificar el programa anterior para que además de escribir en el fichero la salida
estándar también se escriba la salida estándar de error. Comprobar el funcionamiento incluyendo
varias sentencias que impriman en ambos flujos. ¿Hay alguna diferencia si las redirecciones se hacen
en diferente orden?¿Por qué no es lo mismo “ls>dirlist2>&1”que “ls2>&1>dirlist”
*/

#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>


int main(int argc, char **argv)
{
	int out;
	/*
	 Primero se pasa el comando. luego el argumento del comando y luego el direcorio donde se redireccionará
	 la salida estandar
	 */
	char *command_args[] = {argv[1], argv[2],NULL};

	// open input and output files

	//in = open("ina", O_RDONLY);
	out = open(argv[3], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

	// replace standard input with input file

	//dup2(in, 0);

	// replace standard output with output file

	dup2(out, 1);
	dup2(out,2);

	// close unused file descriptors

	//close(in);
	close(out);

	// execute grep

	execvp(argv[1], command_args);

	//exit(EXIT_SUCCESS);
	return 0;
}
