/*
 ============================================================================
 Name        : semaforo-1.c
 Author      : Jorge Shortys
 Version     :
 Copyright   : 
 Description : sincronización de procesos mediante semáforos
 ============================================================================
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEM_HIJO 0
#define SEM_PADRE 1

main(int argc, char *argv [])
{
	int i =10,semid,pid;
	struct sembuf operacion;
	key_t llave;

	//Peticion de un identificador con dos semanforos
	//argv[0]="prueba";
	llave= ftok(argv[0], 'K');
	if ((semid=semget(llave,2, IPC_CREAT | 0600))==-1)
	{
		perror("semget");
		exit(-1);
	}

	//Inicializacion de los semaforos
	//Cerramos el semaforo del proceso hijo
	semctl(semid, SEM_HIJO, SETVAL, 0);

	//Abrimos el semaforo del proceso padre
	semctl(semid, SEM_PADRE, SETVAL, 1);

	//Creacion del proceso hijo
	if ((pid==fork())== -1)
	{
		perror("fork");
		exit(-1);
	}
	else if(pid==0)	//codigo del proceso hijo
	{
		while(i)
		{
			//cerramos eel semaforo del proceso hijo
			operacion.sem_num=SEM_HIJO;
			operacion.sem_op=-1;
			operacion.sem_flg=0;
			semop(semid, &operacion, 1);

			printf("Proceso HIJO: %d\n", i--);

			//Abrimos el semaforo del proceso padre
			operacion.sem_num=SEM_PADRE;
			operacion.sem_op=1;
			semop(semid, &operacion, 1);
		}
		//Borrado del semaforo
		semctl(semid, 0, IPC_RMID,0);
	}
	else	//Codigo del  proceso padre
	{
		operacion.sem_flg= 0;
		while(i)
		{
			//Cerramoe el semaforo del proceso padre
			operacion.sem_num=SEM_PADRE;
			operacion.sem_op= -1;
			semop(semid, &operacion, 1);

			printf("Proceso PADRE: %d\n", i--);

			//Abrimos el semaforo del proceso hijo
			operacion.sem_num= SEM_HIJO;
			operacion.sem_op=1;
			semop(semid, &operacion, 1);
		}
		//Borrado del semaforo
		semctl(semid,0,IPC_RMID,0);
	}
}
