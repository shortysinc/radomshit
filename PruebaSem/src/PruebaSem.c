/*
 ============================================================================
 Name        : PruebaSem.c
 Author      : Jorge Shortys
 Version     :
 Copyright   : 
 Description : Uso del fork()
 ============================================================================
 */

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>


main()
{
	int i=0;
	pid_t fk=fork();
	switch (fk)
	{
	case -1:
		perror("error al crear procesos");
		exit(-1);
		break;

	case 0: //Este es el hijo
		while(i<10)
		{
			sleep(1);
			//printf("\t\t El fork vale: %d\n", fk);
			printf("\t\t Soy el proceso hijo: %d y fork vale-> %d\n", i++, fk);
			break;
		}
	default: //PADRE
		while(i<10)
		{
			//printf("\t\t El fork vale: %d\n", fk);
			printf("Soy el proceso padre: %d y fork vale-> %d\n", i++);
			sleep(2);
		}
	};
	exit(0);
}
