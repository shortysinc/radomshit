/*
 ============================================================================
 Name        : Pr6_ASOR.c
 Author      : Jorge
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

//Vars
int setuid(uid_t uid);
uid_t getuid(void);
uid_t geteuid(void);
uid_t pepe, uidmalo;

/*
	Ejercicio 1. Añadir el código necesario para gestionar correctamente los errores generados por la
	llamada setuid(). Usando la página de manual comprobar el propósito de la llamada setuid y su
	prototipo.
*/

int main()
{
	    setuid(0);
	    printf("%d\n", setuid(0));
		printf("Real UID\t= %d\n", getuid());
	    printf("Effective UID\t= %d\n", geteuid());

	    setuid(1000);
//	    printf("%d\n", setuid(1000));
	    uidmalo=setuid(1000);
//	    printf("%d\n", uidmalo);
	    if (uidmalo==-1)
	    	printf("No existe el usuario con UID: %d\n", 1001);
	    else
	    {
	       	printf("Real UID\t= %d\n", getuid());
	    	printf("Effective UID\t= %d\n", geteuid());
	    }
	    setuid(1001);
	    uidmalo=setuid(1001);
//	    printf("%d\n", uidmalo);

	    if (uidmalo==-1)
	    {
	    	printf("No existe el usuario con UID: %d\n", 1001);

	    }
	    else
	    {
	    	printf("Real UID\t= %d\n", getuid());
	    	printf("Effective UID\t= %d\n", geteuid());
	    }


	    return 1;

}
