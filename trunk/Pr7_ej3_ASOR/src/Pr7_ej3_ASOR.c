/*
 ============================================================================
 Name        : Pr7_ej3_ASOR.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


/*
Ejercicio 3. Escribir un programa que, usando la llamada open, cree un fichero con los permisos
anteriores. Comprobar el resultado y las características del fichero con la orden ls. rw--w--wx
*/



int main()
{
	int fichero = open("/home/jorge/fichero_molon", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IWGRP | S_IWOTH | S_IXOTH);
	if (fichero==-1)
	{
		printf("Error al abrir el fichero\n");
	}
	else

		printf("Se ha podido abrir\n");
	close (fichero);
	return 1;
}
