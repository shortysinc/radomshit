/*
 ============================================================================
 Name        : Pr6_7_ASOR.c
 Ejercicio 1. El comando del sistema id(1) muestra la información de
 usuario real y efectiva.
 Consultar la página de manual y comprobar el funcionamiento del comando.

 Ejercicio 2. Escribir un programa que muestre igual que el comando id los uid efectivos y real del
 usuario. ¿En qué circunstancias podríamos asegurar que el fichero tiene activado el bit setuid?.

 Ejercicio 3. Modificar el programa anterior para que se muestre además el nombre de login,
 directorio home e información de usuario del usuario real.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{
	printf("El id de usuario actual es %d\n",getuid());
	printf("El id efectivo de usuario actual es %d\n",geteuid());
	printf("El id real del grupe es %d\n",getgid());
//	printf("El id efectivo de usuario actual es %d",get);
	return 1;
}
