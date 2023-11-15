#include "main.h"

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
* commands like `exit` and `env`,
* and more.
*/


int main(void)
{
	char *command;
	char *args[MAX_NUM_ARGS];

	while (1)
	{
		printf("$ ");
		command = read_line();
		parse_args(command, args);
		execute_command(args);
	}

	return 0;
}
