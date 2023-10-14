#include "main.h"
/**
 * tokenization - A function that tokezes the path
 */
int tokenization(char *token)
{
	char *line;

	char *delimiters = " \n";

	char *command_arguments[1024];

	int _index = 0;
	/* Tokenizing our string input */
	token = strtok(line, delimiters);
	while(token != NULL)
	{
		command_arguments[_index] = token;
		token = strtok(NULL, delimiters);
		_index++;
	}
	command_arguments[_index] = NULL;
	/*Checking if command is builtin command */
	if (strcmp(command_arguments[0], "cd") == 0)
	{
		/* Call the builtin cd function */
		cd_builtin(command_arguments[1]);
	}
	else if (strcmp(command_arguments[0], "exit") == 0)
	{
		/* Call the exit builtin function */
		exit_builtin();
	}
	else
	{
		_pid();
	}
}
/**
 * _pid - a function that starts a new program, child program
 */
int _pid(void)
{
	char *command_arguments[1024];

	char *line;

	size_t pid;

	pid = fork();
	if(pid == -1)
	{
		perror("Forking Failed");
		free(line);
		return(-1);
	}
	else if (pid == 0)
	{
		char *path_command = get_path_check(command_arguments[0]);
		if (path_command != NULL)
		{
			execve(path_command, command_arguments, environ);
			/* error message fucntion here */
			error_message(command_arguments[0]);
			free(line);
			exit(1);
		}
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
	}
}
