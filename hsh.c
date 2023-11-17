#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * hsh_loop - Simple UNIX command line interpreter.
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
	char buffer[BUFFER_SIZE];
	pid_t pid = fork();

	while (1)
	{
		printf("#cisfun$ ");
		if (!fgets(buffer, BUFFER_SIZE, stdin))
			break;

		buffer[strcspn(buffer, "\n")] = '\0';

		if (strcmp(buffer, "exit") == 0)
			break;
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execlp(buffer, buffer, NULL);
			perror("exec");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, NULL, 0);
		}
	}
	return (0);
}
