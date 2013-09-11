/*
 ============================================================================
 Name        : PruebaFork.c
 Author      : Jorge Shortys
 Version     :
 Copyright   : 
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void imprime (int a, int b)
{
	printf("a= %d  y b=%d\n", a,b);
}
void main() {
	int a = 3;
	int i;
	{
		int b=2;
		int p;
		for (i=0;i<4;i++)
		{
			p=fork();
			printf("a vale %d y b %d y i %d y 		pid %d pidpadre %d\n", a,b,i,p, getppid());
			if (p==0)
			{
				b++;
				execlp(NULL,NULL,NULL);
				a++;
			}
			else {
				wait();
				imprime(a,b);
				a++;
				b--;
			}
		}
		imprime(a,b);
	}

}
