#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/*
Ejercicio 2. Escribir un programa en C que abra la tubería con nombre anterior ($HOME/tuberia) en
modo solo escritura, y escriba en ella el primer argumento del programa. En otro terminal, leer de la
tubería usando un comando adecuado.

*/

int main(int argc, char **argv)
{
	system ("rm /home/usuario_vms/tuberia");
	//int result;

	int lol = mkfifo("/home/usuario_vms/tuberia", 0666);
	if (lol < 0)
	{
		perror ("Fallo al crear el pipe");
		exit (1);
	}

	else
	{
		int fd = open("/home/usuario_vms/tuberia", O_WRONLY);
		write(fd, argv[1],strlen(argv[1]));
	}
	return 0;

}
