
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * set_environment_variable - initialize and modifies environment variables
 * @variable: variable name
 * @value: sets the environment variable
 * Return: 0 on success, -1 on failure
 */

int set_environment_variable(char *variable, char *value)
{
	if (variable == NULL || value == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	if (setenv(variable, value, 1) == -1)
	{
		perror("setenv");
		return (-1);
	}

	return (0);
}
