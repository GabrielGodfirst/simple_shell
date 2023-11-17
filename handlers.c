#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
* read_line - Read a line of input from the user.
*
* Return: A pointer to the string containing the input.
*/

char *read_line(void)
{

	char buffer[MAX_INPUT_SIZE];
	char *result;

	if (!fgets(buffer, MAX_INPUT_SIZE, stdin))
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}

	result = malloc(strlen(buffer) + 1);
	if (result == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	strcpy(result, buffer);

	return result;
}
