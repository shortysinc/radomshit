/*
 ============================================================================
 Ejercicio 3. Escribir un programa que obtenga la información de
 configuración del sistema, consultar sysconf(3), e imprima por ejemplo,
 la longitud máxima de los argumentos, el número máximo de
 hijos y el número máximo de ficheros.

 Ejercicio 4. Repetir el ejercicio anterior pero en este caso para
 la configuración del sistema de ficheros, pathconf(3). Por ejemplo
 que muestre el número máximo de enlaces, el tamaño máximo de una ruta
 y el de un nombre de fichero.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main(void)
{
	printf("El numero maximo de argumento es %ld\n", sysconf(_SC_ARG_MAX));
	printf("El numero maximo de hijos es %ld\n", sysconf(_SC_CHILD_MAX));
	printf("El numero maximo de ficheros es %ld\n", sysconf(_SC_OPEN_MAX));

	printf("El numero maximo de enlaces de / es %ld\n", pathconf("/",_PC_LINK_MAX));
	printf("El numero maximo de enlaces de / es %ld\n", pathconf("/",_PC_PATH_MAX));
	return 1;
}
