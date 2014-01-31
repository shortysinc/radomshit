/*
 * Ejercicio 1. Comunicación por tuberías. Escribir un programa que emule el comportamiento de la shell
en la ejecución de una sentencia en la forma: c m n o a g m n o 1 | c m n o a g m n o . El
                                                  oad1 ruet                 oad2 ruet2
programa abrirá una tubería sin nombre y creará un hijo:
    ● El programa padre ejecutará “comando1 argumento1” y redireccionará la salida estándar al
         extremo de escritura.
    ● El hijo, ejecutará “comando2 argumento2”, en este caso la entrada estándar deberá duplicarse
         con el extremo de lectura de la tubería.
    ● Probar el funcionamiento con una sentencia similar a: . e e c c o e h 1 3 5 w -
                                                              /jrii1 co 24 c c
    ● Nota: antes de ejecutar el comando correspondiente deben cerrarse todos los descriptores no
         necesarios.
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
	  int des_p[2];
	        if(pipe(des_p) == -1) {
	          perror("Pipe failed");
	          exit(1);
	        }

	        if(fork() == 0)        //first fork
	        {
	            close(1);          //closing stdout
	            dup(des_p[1]);     //replacing stdout with pipe write
	            close(des_p[0]);   //closing pipe read
	            close(des_p[1]);

	            const char* prog1[] = { "echo", "123456", 0};
	            execvp(prog1[0], prog1);
	            perror("execvp of ls failed");
	            exit(1);
	        }

	        if(fork() == 0)        //creating 2nd child
	        {
	            close(0);          //closing stdin
	            dup(des_p[0]);     //replacing stdin with pipe read
	            close(des_p[1]);   //closing pipe write
	            close(des_p[0]);

	            const char* prog2[] = { "wc", "-c", 0};
	            execvp(prog2[0], prog2);
	            perror("execvp of wc failed");
	            exit(1);
	        }

	        close(des_p[0]);
	        close(des_p[1]);
	        wait(0);
	        wait(0);
	        return 0;
}
