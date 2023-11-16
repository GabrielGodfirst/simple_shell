#include "main.h"

/**
* parse_args - Parse the command line into arguments.
*
* @command: The command line to parse.
* @args:    An array to store the parsed arguments.
*/

void parse_args(char *command, char *args[])
{

	char *token;
	int i = 0;

	token = strtok(command, " \t\r\n\a");
	while (token != NULL && i < MAX_NUM_ARGS - 1)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " \t\r\n\a");
	}
	args[i] = NULL;

	if (i > 0)
	{
		if (strcmp(args[0], "exit") == 0)
		{
			handle_exit(args[1]);
		}
		else
		{
			execute_command(args);
		}
	}
}
