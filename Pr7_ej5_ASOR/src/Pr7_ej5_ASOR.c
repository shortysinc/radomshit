/*
 ============================================================================
 Name        : Pr7_ej5_ASOR.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
Ejercicio 5. Modificar el ejercicio 3 para que antes de crear el fichero se fije la máscara igual que en
el ejercicio anterior. Una vez creado el fichero debe restaurarse la máscara original del proceso.
Comprobar el resultado con el comando ls. rw--w--wx
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
// En shell, el valor de umask se crea poniendo a 1 los flags que se quieren capar.
// Ej umask = 027 es lo mismo que umask u=rwx,g=rwx,o=
int main()
{
	mode_t oldmask = umask((mode_t) 0);
	umask(S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH);
	int fichero = open("/home/usuario_vms/fichero_molon", O_RDWR | O_CREAT,S_IRUSR | S_IWUSR | S_IWGRP | S_IWOTH | S_IXOTH);
	if (fichero==-1)
	{
		printf("Error al abrir el fichero\n");
	}
	else

		printf("Se ha podido abrir\n");

	umask(oldmask);
	return 1;

  /*int fd;
  mode_t oldmask;

  printf("Your old umask is %i\n",oldmask=umask(S_IRWXG));
  if ((fd = creat("umask.file", S_IRWXU|S_IRWXG)) < 0)
    perror("creat() error");
  else {
    system("ls -l umask.file");
    close(fd);
    //unlink("umask.file");
  }
  umask(oldmask);

  return 1;
*/
}
