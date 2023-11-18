#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

/**
* execute_commands - Execute command statements
* @commands: The command string to execute
*/

void execute_commands(char *commands)
{

	char *token;
	pid_t pid;

	while ((token = strtok(commands, ";")))
	{
		while (*token == ' ' || *token == '\t' || *token == '\n')
		{
			token++;
		}
		char *end = token + strlen(token) - 1;

		while (end > token && (*end == ' ' || *end == '\t' || *end == '\n'))
	{

		end--;
	}
		end[1] = '\0';

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);

			else if (pid == 0)
			{
				if (system(token) == -1)
				{
					perror("system");
					exit(EXIT_FAILURE);
				}
				exit(EXIT_SUCCESS);

			}
			else
			{
				waitpid(pid, NULL, 0);
			}

			commands = NULL;
		}
}
