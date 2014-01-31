/*
 * ---------------ls extendido--------------------: popopo
 * Escribir un programa que cumpla las siguientes especificaciones:
    ● El programa tiene un único argumento que es la ruta a un directorio. El programa debe
         comprobar la corrección del argumento. HECHO!
    ● El programa recorrerá las entradas del directorio de forma que:
             ○ Si es un fichero normal escribirá el nombre.
             ○ Si es un directorio escribirá el nombre seguido del carácter ‘/’
             ○ Si es un enlace simbólico escribirá el nombre seguido de ‘-><fichero al que apunta>’.
                 Usar la función readlink(2), dimensionar adecuadamente el buffer de la función.
             ○ Si el fichero es ejecutable escribirá el nombre seguido del carácter ‘*’
    ● Al final de la lista el programa escribirá el tamaño total que ocupan los ficheros (no
         directorios) en kilobytes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
int main(int argc, char **argv)
{
	int n;
	struct stat sbuf;
	//Si no se pasa argumento, por defecto es null. Con lo cual argc = 1.
	//printf("%d\n",argc);
	if (argc <2 ) {
		printf("me estas vacilando hijo de puta?\n");
		exit(-1);
	}

	//Este bucle for comprueba si lo que le hemos pasado es un directorio

	for( n = 1; n < argc; ++n ) {
		if( lstat( argv[n], &sbuf ) == -1 )
			perror( argv[n] );

		//Con esta estructura comprueba directamente la correcion de la ruta para ver si es un directorio
		//o si es otra cosa. No hace falta parsearlo caracter a caracter.
		else if( S_ISDIR( sbuf.st_mode ) ) {
			printf( "%s is a directory \n", argv[n] );

		}
		else {
			printf( "%s is not a directory \n", argv[n] );
		}
	}



	return 0;
}
