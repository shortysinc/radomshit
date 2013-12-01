/*
 ============================================================================
 Name        : Pr64_ASOR.c

 Ejercicio 1. El comando del sistema uname(1) muestra información
 sobre diversos aspectos del sistema. Consultar la página de
 manual, y obtener la información del sistema.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>



int main(void)
{
	struct utsname uts;
	if (uname(&uts) < 0)
	    perror("uname() error");
	else
	{
		printf("Sysname:  %s\n", uts.sysname);
		printf("Nodename: %s\n", uts.nodename);
		printf("Release:  %s\n", uts.release);
		printf("Version:  %s\n", uts.version);
		printf("Machine:  %s\n", uts.machine);
	}
	return 1;
}
