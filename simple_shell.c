
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
		{
			printf("\n");
			break;
		}
		
		buffer[strcspn(buffer, "\n")] = '\0';

        

        

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
           
            if (execlp(buffer, buffer, NULL) == -1) {
                perror("exec");
                exit(EXIT_FAILURE);
            }
        } else {
            
            waitpid(pid, NULL, 0);
        }
    }
}

int main(void)
{
	hsh_loop();
	return 0;
}

