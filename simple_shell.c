#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
* main - Simple UNIX command line interpreter.
*
* Return: 0 on successful execution, -1 on failure.
*
* This program acts as a basic shell,
* allowing users to input commands,
* displaying a prompt, and executing
* the entered command. It supports
* basic functionalities such as handling
* command lines with arguments,
* managing the PATH, implementing built-in
zi commands like `exit` and `env`,
*  and more.
*/


#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(void)
{

	char *command;
	char buffer[BUFFER_SIZE];
	int status;
	pid_t pid;

	while (1)
	{
		printf("#cisfun$ ");
		if (!fgets(buffer, BUFFER_SIZE, stdin))
		{
			printf("\n");
			break;
		}

		command = strtok(buffer, "\n");

		if (strcmp(command, "exit") == 0)
		{
			printf("Exiting shell...\n");
			break;
		}

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			char *args[2];
			args[0] = command;
			args[1] = NULL;
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

	return (0);
}
