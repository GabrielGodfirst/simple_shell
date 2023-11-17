
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"
/**
 * execute_commands - executed command statement
 * @main:Entry point
 * @char: character of the function
 */


void execute_commands(char *commands)
{
	char *token;
	pid_t pid = fork();

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

		if (pid == -1)
		{
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (system(token) == -1)
			{
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

int main(void)
{
	char input[1024];

	printf("Enter commands separated by ';':\n");
	fgets(input, sizeof(input), stdin);
	char *newline = strchr(input, '\n')

	if (newline != NULL)
	{
		*newline = '\0';
	}
	execute_commands(input);
	return (0);
}

