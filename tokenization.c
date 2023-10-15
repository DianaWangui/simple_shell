#include "main.h"
/**
 * tokenization - A function that tokezes the path
 */
int tokenization(char *line, char *command_arguments[])
{
	char *token;
	/* char *line = NULL;*/

	char *delimiters = " \n";

	char *command_arguments[2040];

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
		_pid(command_arguments);
	}
	/* free(line);*/
	return (0);
}
/**
 * _pid - a function that starts a new program, child program
 */
int _pid(char *command_arguments[])
{
	char *command_arguments[1024];

	char *line = NULL;

	int pid;

	char *path_command;

	int status;

	pid = fork();
	if(pid == -1)
	{
		perror("Forking Failed");
		free(line);
		return(-1);
	}
	else if (pid == 0)
	{
		printf("this is a child process\n");
		path_command = get_path_check(command_arguments[0]);
		printf("This is the path");
		if (path_command != NULL)
		{
			printf("Not null path");
			execve(path_command, command_arguments, environ);
			/* error message fucntion here */
			error_message(command_arguments[0]);
			free(line);
			exit(1);
		}
	}
	else
	{
		printf("This is a parent process\n");
		waitpid(pid, &status, 0);
	}
	/*free(line);*/
	return (0);
}
