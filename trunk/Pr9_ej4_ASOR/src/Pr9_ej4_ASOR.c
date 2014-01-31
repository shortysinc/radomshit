#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "errno.h"
#include "fcntl.h"
#include "pthread.h"

/*

Ejercicio 1. Crear otra tubería con nombre (ej. tuberia2). Escribir un programa que espere hasta que
haya datos listos para leer en alguna de ellas. El programa debe escribir la tubería desde que se leyó y
los datos leídos. Consideraciones:
     ● Para optimizar las operaciones usar un búfer para la lectura (ej. de 256 bytes).
     ● Usar read(2) para leer de la tubería y gestionar adecuadamente la longitud de los caracteres
         leídos.
     ● Las operaciones open(2) serán bloqueantes (hasta que se abra el otro extremo para escritura),
         puede usarse la opción O_NONBLOCK.
     ● Cuando el escritor termina y cierra la tubería, select considerará siempre listo el descriptor
         (para leer EOF) y no bloqueará. En este caso hay que reabrir la tubería o se puede abrir la
         tubería en el selector como lectura/escritura. Comprobar este punto abriendo las tuberías con
         diferentes opciones.


 */

int main() //NO FUNCA
{
	system ("rm /home/usuario_vms/tuberia1");
	system ("rm /home/usuario_vms/tuberia2"); // Para la pregunta de si se pueden crear 2 pipes
	//int result;

	int lol1 = mkfifo("/home/usuario_vms/tuberia1", 0666);
	int lol2 = mkfifo("/home/usuario_vms/tuberia2", 0666);
	if (lol1 < 0 || lol2 <0)
	{
		perror ("Fallo al crear un pipe");
		exit (1);
	}

	else
	{
		fd_set rfds;
		open(lol1, O_CREAT | O_RDWR, O_NONBLOCK );
		open(lol2, O_CREAT | O_RDWR, O_NONBLOCK );
		struct timeval tv;
		int valret;
		char *buffer = malloc (256);
		// Mirar stdin (df 0) para ver si tiene entrada
		FD_ZERO(&rfds);
		FD_SET(0, &rfds);
		// Esperar hasta 5 s
		tv.tv_sec = 5;
		tv.tv_usec = 0;
		// Implement the receiver loop
		while(1)
		{

			valret = select(1, &rfds, NULL, NULL, &tv);

			if (valret > 0 && FD_ISSET(0, &rfds)) {

				// Clear flags
				FD_CLR(0, &rfds);
				// Do a simple read on data
				read(0, &buffer, sizeof(buffer));
				// Dump read data
				printf("\nReader: %s", buffer);
			}

		}
	}
	/*
	 #include <stdio.h>
       #include <sys/time.h>
       #include <sys/types.h>
       #include <unistd.h>

       int
       main(void) {
           fd_set rfds;
           struct timeval tv;
           int valret;

           // Mirar stdin (df 0) para ver si tiene entrada
           FD_ZERO(&rfds);
           FD_SET(0, &rfds);
           // Esperar hasta 5 s
           tv.tv_sec = 5;
           tv.tv_usec = 0;

           valret = select(1, &rfds, NULL, NULL, &tv);
           // ¡No confiar ahora en el valor de tv!

           if (valret)
               printf("Los datos ya están disponibles.\n");
               // FD_ISSET(0, &rfds) será verdadero
           else
               printf("Ningún dato en 5 segundos.\n");

           return 0;
       }

	 */
	return 0;

}
