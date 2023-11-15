
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * handle_exit - takes care of the 'exit' with arguments
 * @status: provives exit status as string
 */

void handle_exit(char *status)
{
	int exit_status = atoi(status);

	if (status == NULL)
	{
		fprintf(stderr, "Usage: exit status\n");
		return;
	}
	exit(exit_status);
}
