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

/**
* parse_args - Parse the command line into arguments.
*
* @command: The command line to parse.
* @args:    An array to store the parsed arguments.
*/

void parse_args(char *command, char *args[])
{

	int i = 0;

	args[i++] = strtok(command, " ");
	while ((args[i++] = strtok(NULL, " ")) != NULL)
	{
		/* Empty loop body intentionally left blank*/
	}
}

/**
* execute_command - Execute the parsed command.
*
* @args: The array of arguments to execute.
*/

void execute_command(char *args[])
{

	int status;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
