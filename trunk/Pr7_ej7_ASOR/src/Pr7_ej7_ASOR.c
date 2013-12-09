/*
Ejercicio 7. Escribir un programa que emule el comportamiento del comando stat y muestre:
    ● el número major y minor asociado al dispositivo,
    ● el número de inodo del archivo
    ● el tipo de archivo (directorio, enlace simbólico o archivo ordinario)
    ● La hora en la que se creó el fichero
*/
//http://man7.org/tlpi/code/online/dist/files/t_stat.c.html
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
//#include <sys/mkdev.h>

int main()
{
	struct stat sb;
//	//printf("Major: %d\n", major);
//	printf("Dispositivo : major=%ld  minor=%ld\n",(long) major(sb->st_dev), (long) minor(sb->st_dev));
//	printf("I-node number: %ld\n", (long) sb->st_ino);
	if (stat("/home/jorge/ninio", &sb) == -1)
	{
		perror("stat");
		exit(EXIT_FAILURE);
	}

	//A esto lo saque del manual de STAT
	printf("File type:                ");

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

	printf("Dispositivo : major=%ld  minor=%ld\n",(long) major(sb.st_dev), (long) minor(sb.st_dev));
	printf("I-node number:            %ld\n", (long) sb.st_ino);

	printf("Last status change:       %s", ctime(&sb.st_ctime));
	printf("Last file access:         %s", ctime(&sb.st_atime));
	printf("Last file modification:   %s", ctime(&sb.st_mtime));

	exit(EXIT_SUCCESS);
}
