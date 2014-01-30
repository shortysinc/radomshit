/*
Ejercicio 1. Escribir un programa que redirija la salida estándar a un fichero, cuya ruta se pasa como
primer argumento. Probar escribiendo varias cadenas en la salida estándar.

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

	// close unused file descriptors

	//close(in);
	close(out);

	// execute grep

	execvp(argv[1], command_args);

	//exit(EXIT_SUCCESS);
	return 0;
}
