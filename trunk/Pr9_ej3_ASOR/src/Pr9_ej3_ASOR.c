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

int main()
{
	system ("rm /home/usuario_vms/tuberia1");
	system ("rm /home/usuario_vms/tuberia2");
	//int result;

	int lol1 = mkfifo("/home/usuario_vms/tuberia1", 0666);
	int lol2 = mkfifo("/home/usuario_vms/tuberia2", 0666);
	if (lol1 < 0 || lol2 <0)
	{
		perror ("Fallo al crear un pipe");
		exit (1);
	}

	else
	{
		char * buffer = "";
		int fd1 = open("/home/usuario_vms/tuberia1", O_RDONLY);
		//int fd2 = open("/home/usuario_vms/tuberia2", O_RDONLY);
		read(fd1, buffer, sizeof(buffer));
	}
	return 0;

}
