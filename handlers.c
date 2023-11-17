#include "main.h"

/**
* read_line - Read a line of input from the user.
*
* Return: A pointer to the string containing the input.
*/

char *read_line(void)
{

	char buffer[MAX_INPUT_SIZE];

	if (!fgets(buffer, MAX_INPUT_SIZE, stdin))
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}

	return strdup(buffer);
}
