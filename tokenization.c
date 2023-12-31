#include "main.h"
/**
 * tokenization - A function that tokezes the path
 * @line: The line containing the user input
 * Return: 0 success
 */
int tokenization(char *line)
{
	char *token;
	char *delimiters = " \a\n\t\r";
	char *command_arguments[1024];
	int _index = 0;

	token = strtok(line, delimiters);
	while (token != NULL)
	{
		command_arguments[_index] = token;
		token = strtok(NULL, delimiters);
		_index++;
	}
	command_arguments[_index] = NULL;
	if (command_arguments[0] == NULL)
	{
		return (0);
	}
	if (stringmp(command_arguments[0], "cd") == 0)
	{
		cd_builtin(command_arguments[1]);
	}
	else if (stringmp(command_arguments[0], "exit") == 0)
	{
		free(line);
		exit_builtin();
	}
	else if (stringmp(command_arguments[0], "env") == 0)
	{
		env_builtin();
	}
	else
	{
		_pid(command_arguments);
	}
	return (0);
}
/**
 * _pid - a function that starts a new program, child program
 * @command_arguments: The command argument passed as input
 * Return: 0 success
 */
int _pid(char *command_arguments[])
{

	char *line = NULL;

	int pid;

	char *path_command;

	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Forking Failed");
		free(line);
		return (-1);
	}
	else if (pid == 0)
	{
		path_command = get_path_check(command_arguments[0]);
		if (path_command != NULL)
		{
			execve(path_command, command_arguments, environ);
			free(line);
			error_message(command_arguments[0]);
			exit(1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	/*free(line);*/
	return (0);
}
