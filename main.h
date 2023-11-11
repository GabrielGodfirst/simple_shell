#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/* Required Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

/* Macros */
#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 64
#define MAX_NUM_ARGS 32

/* Function Declarations */
void display_prompt(void);
int read_input(char *buffer);
void execute_command(char *command);
int tokenize_input(char *input, char *args[]);
void handle_path(char *command, char *args[]);
void handle_exit(void);
void handle_env(void);
void handle_cd(char *args[]);
void handle_semicolon(char *commands);
void handle_logical_operators(char *commands);
void handle_alias(char *args[]);
void handle_variables(void);
void handle_comments(void);
void handle_file_input(char *filename);

#endif /* SIMPLE_SHELL_H */

