#include "main.h"
/**
 * exec_command - function that executes a command
 * @command: This is the command to be executed
 */
void exec_command(const char *command)
{
	char *envp[] = {NULL};

	int exec_result;

	int status;

	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if(child_pid == 0)
	{
		exec_result = execve(command, NULL, envp);
		if (exec_result == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(child_pid, &status, 0);
			printf("Child process exited with status %d\n", status);
		}
	}
}
