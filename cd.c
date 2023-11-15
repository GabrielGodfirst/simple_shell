
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * change_directory - change the working directory
 * @directory: the working directory
 * Return: 0 on success, -1 on failure
 */

int change_directory(char *directory)
{
	char *home_dir = getenv("HOME");
	char *prev_dir = getenv("PWD");

	if (directory == NULL)
	{
		directory = home_dir;
	}
	else if (strcmp(directory, "-") == 0)
	{
		directory = prev_dir;
	}

	if (chdir(directory) == -1)
	{
		perror("chdir");
		return (-1);
	}

	if (setenv("PWD", directory, 1) == -1)
	{
		perror("setenv");
		return (-1);
	}

	return (0);
}
