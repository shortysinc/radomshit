/*
Ejercicio 7. Escribir un programa que emule el comportamiento del comando stat y muestre:
    ● el número major y minor asociado al dispositivo,
    ● el número de inodo del archivo
    ● el tipo de archivo (directorio, enlace simbólico o archivo ordinario)
    ● La hora en la que se creó el fichero
*/
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


int main()
{
	struct stat sb;
	if (stat("/home/usuario_vms/bitch", &sb) == -1)
	{
		perror("stat");
		exit(EXIT_FAILURE);
	}

	//man 2 stat
	printf("Major y Minor(dispositivo): Major=%ld  Minor=%ld\n",
		  (long) major(sb.st_dev), (long) minor(sb.st_dev));
	printf("Tipo de archivo:                ");
	// Se hace la AND del modo con la máscara S_IFMT para ver el tipo de fichero
	// switch para comprobarlo...
	switch (sb.st_mode & S_IFMT) {
	case S_IFBLK:  printf("block device\n");            break;
	case S_IFCHR:  printf("character device\n");        break;
	case S_IFDIR:  printf("directory\n");               break;
	case S_IFIFO:  printf("FIFO/pipe\n");               break;
	case S_IFLNK:  printf("symlink\n");                 break;
	case S_IFREG:  printf("regular file\n");            break;
	case S_IFSOCK: printf("socket\n");                  break;
	default:       printf("unknown?\n");                break;
	}

	printf("Numero de I-Nodo:       %ld\n", (long) sb.st_ino);
	printf("Ultimo cambio:       	%s", ctime(&sb.st_ctime));
	printf("Ultimo Acceso:          %s", ctime(&sb.st_atime));
	printf("Ultima Modificacion:    %s", ctime(&sb.st_mtime));

	exit(EXIT_SUCCESS);
}
