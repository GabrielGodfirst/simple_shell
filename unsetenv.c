
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * unset_environment_variable - takes out env variable
 * @variable: name of the removed var
 * Return: 0 on success, -1 on failure
 */

int unset_environment_variable(char *variable)
{
	if (variable == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	if (unsetenv(variable) == -1)
	{
		perror("unsetenv");
		return (-1);
	}

	return (0);
}
