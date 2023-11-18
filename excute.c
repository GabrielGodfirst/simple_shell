#include "main.h"

/**
* execute_commands - Execute command statements
* @commands: The command string to execute
*/

void execute_commands(char *commands)
{
	/* Implementation of execute_commands function goes here*/

}

/**
* Main - Entry point of the progrm
*
*Return: 0 on success
*/

int main(void)
{

	char input[1024];

	printf("Enter commands separated by ';':\n");

	fgets(input, sizeof(input), stdin);

	char *newline = strchr(input, '\n');

	if (newline != NULL)
	{

		*newline = '\0';
	}

	execute_commands(input);

	return (0);
}
