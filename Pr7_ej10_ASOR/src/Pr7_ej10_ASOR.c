/*
Ejercicio 2. Escribir un programa que consulte y muestre en pantalla el estado del cerrojo sobre un
fichero. El proceso mostrará el estado del cerrojo (bloqueado, desbloqueado). Además:
    ● si está desbloqueado, fijará un cerrojo de escritura y escribirá la hora actual. Después
         suspenderá su ejecución durante 30 segundos (función sleep) y a continuación liberará el
         cerrojo.
    ● Si el cerrojo está bloqueado terminará el proceso.
El programa no deberá modificar el contenido del fichero si no tiene el cerrojo.

 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main()
{
	char* file= "/home/usuario_vms/bitch";
	int fd;
	struct flock lock;
	printf ("opening %s\n", file);
	/* Open a file descriptor to the file. */
	fd = open (file, O_WRONLY);
	printf ("locking\n");
	/* Initialize the flock structure. */
	memset (&lock, 0, sizeof(lock));
	if (lock.l_type == F_RDLCK || lock.l_type == F_RDLCK ) {

	} else {

	}



	return 0;
}
