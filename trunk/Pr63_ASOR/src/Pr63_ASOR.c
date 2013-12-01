#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <errno.h>

int main()
{
	int i;
	for (i = 0; i < sys_nerr; i++)
	{
		printf("%s\n", sys_errlist[i]);
	}
	return 1;
}
