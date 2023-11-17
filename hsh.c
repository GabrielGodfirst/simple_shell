
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUFFER_SIZE 512

/**
 * hsh_loop - Simple UNIX command line interpreter.
 * main - runs the loop
 * Return: 0 on successful execution, -1 on failure.
 * This program acts as a basic shell,
 * allowing users to input commands,
 * displaying a prompt, and executing
 * the entered command. It supports
 * basic functionalities such as handling
 * command lines with arguments,
 * managing the PATH, implementing built-in
 * commands like `exit` and `env`,
 * and more.
 */

void hsh_loop(void)
{
	char buffer[MAX_BUFFER_SIZE];
	pid_t pid = fork();

	while (1)
	{
		printf("#cisfun$ ");
		if (!fgets(buffer, MAX_BUFFER_SIZE, stdin))
		{
			printf("\n");
			break;
		}

		buffer[strcspn(buffer, "\n")] = '\0';

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execlp(buffer, buffer, NULL) == -1)
			{
				perror("exec");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, NULL, 0);
		}
	}
}
