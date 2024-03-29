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
#include <time.h>

int main()
{
	char* file= "/home/usuario_vms/bitch";
	int fd;
	struct flock lock;
	time_t ltime;
	time(&ltime);

	printf ("Opening %s\n", file);
	/* Open a file descriptor to the file. */
	fd = open (file, O_WRONLY);
	printf ("Locking...\n");
	/* Initialize the flock structure. */
	memset (&lock, 0, sizeof(lock));
//	lock.l_type=F_UNLCK; // Aquí se mete el bloqueo
	lock.l_type=F_WRLCK;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_whence= SEEK_SET;
	lock.l_pid=getpid();
	// La siguiente llamada no es necesaria para bloquearlo, pero como no hace nada
	// la dejamos
//	if (fcntl(fd, F_SETLKW, &lock) == -1) {
//		perror("fcntl");
//		exit(1);
//	}

	int locked = 0;
	locked=fcntl(fd, F_GETLK,&lock); // Con F_GETLK devuelve el pid del proceso que lo bloquea, supuestamente
	printf("Locked= %d\n", locked);
	if(locked != -1){
		printf("Está to pillao");
	}
	else{
		lock.l_type= F_WRLCK;//Bloqueo el cerrojo
		locked=fcntl(fd, F_GETLK,&lock);//compruebo que se ha bloqueado
		printf("Locked= %d\n", locked);//devuelvo el valor del bloqueo
		printf("the time is %s", ctime(&ltime));
		sleep (1);
		lock.l_type= F_UNLCK;
		locked=fcntl(fd, F_GETLK,&lock);
		printf("Locked= %d\n", locked);
		}

	return 0;
}
