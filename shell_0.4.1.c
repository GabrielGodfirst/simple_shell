#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* handle_exit - takes care of the 'exit' with argument* @status: provides exit status as string
*/

void handle_exit(char *status)
{

	int exit_status;

	if (status == NULL)
	{
		fprintf(stderr, "Usage: exit status\n");
		return;
	}

	exit_status = atoi(status);
	exit(exit_status);
}
