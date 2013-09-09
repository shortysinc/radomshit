/*
 ============================================================================
 Name        : PruebaExamen.c
 Author      : Jorge Shortys
 Description : Feb 2013 Cuestion 5
			   Indique si la ejecución del código generará algún error.
			   En cualquier caso, ¿cuál será el contenido del fichero prueba
			   al finalizar la ejecución? Justifique la respuesta.
 ============================================================================
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char buf1[4] = "XXXX";
char buf2[4] = "AAAA";
int main() {
	int fd1,fd2;
	fd1=open("prueba",O_RDWR | O_CREAT | O_TRUNC, 0666 );
	if ( fork() == 0) {
		fd2=open("prueba",O_RDWR );
		write(fd1,buf1,4);
		write(fd2,buf2,4);
		close(fd2);
		close(fd1);
	}
	else {
		write(fd1,buf1,4);
		wait(NULL);
		read(fd1,buf2,4);
		close(fd1);
	}
}
