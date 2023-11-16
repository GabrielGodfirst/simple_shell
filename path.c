#include "main.h"

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
		/* Check if the command exists in PATH*/
		if (execvp(args[0], args) == -1)
		{
			/* If execvp fails, print an error message*/
			fprintf(stderr, "Command not found: %s\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
