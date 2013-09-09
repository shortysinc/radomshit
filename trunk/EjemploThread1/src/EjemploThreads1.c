/*
 ============================================================================
 Name        : EjemploThreads1.c
 Author      : Jorge Shortys
 Version     :
 Copyright   : 
 ============================================================================
 */

#include <stdio.h>
#include <pthread.h>
#define MAX_THREADS 10
void func(void) {
	printf("Thread %d \n", pthread_self());
	pthread_exit(0);
}
main() {
	int j;
	pthread_attr_t attr;
	pthread_t thid[MAX_THREADS];
	pthread_attr_init(&attr);
	for(j = 0; j < MAX_THREADS; j ++)
		pthread_create(&thid[j], &attr, func, NULL);
	for(j = 0; j < MAX_THREADS; j ++)
		pthread_join(thid[j], NULL);
}
