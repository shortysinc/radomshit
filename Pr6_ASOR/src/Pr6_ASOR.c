/*
 ============================================================================
 Name        : Pr6_ASOR.c
 Author      : 
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

//Vars
int setuid(uid_t uid);
uid_t getuid(void);
uid_t geteuid(void);
int pepe;

/*
	Ejercicio 1. Añadir el código necesario para gestionar correctamente los errores generados por la
	llamada setuid(). Usando la página de manual comprobar el propósito de la llamada setuid y su
	prototipo.
*/

int main() {
//	printf("Mehhhhhhhhh");
//	return EXIT_SUCCESS;
		setuid(0);
	    printf("Real UID\t= %d\n", getuid());
	    printf("Effective UID\t= %d\n", geteuid());
	    printf("Real GID\t= %d\n", getgid());
	    printf("Effective GID\t= %d\n", getegid());

	    setuid(1001);
	    printf("Real UID\t= %d\n", getuid());
	    printf("Effective UID\t= %d\n", geteuid());
	    printf("Real GID\t= %d\n", getgid());
	    printf("Effective GID\t= %d\n", getegid());

	    setuid(80);
	    printf("Real UID\t= %d\n", getuid());
	    printf("Effective UID\t= %d\n", geteuid());
	    printf("Real GID\t= %d\n", getgid());
	    printf("Effective GID\t= %d\n", getegid());
	    return 1;

}
