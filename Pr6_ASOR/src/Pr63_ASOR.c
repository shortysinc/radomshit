#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <errno.h>

void main2()
{
	int i;
	for (i = 0; i < sizeof(char); i++)
	{
		printf("%s\n", &sys_errlist[i]);
	}
}
