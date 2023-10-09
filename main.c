#include "main.h"
/**
 * main - The main function to read use input
 * Return: 0 on success
 */
int main(void)
{
	int char_read;

	size_t len = 0;

	char *line = NULL;

	char *delimiter = " ";

	char *input_command;

	write(1, "Simple_shell$ ", 14);

	char_read = getline(&line, &len, stdin);
	if (char_read == -1)
	{
		perror("Error handling input");
		exit(-1);
	}
	else
	{
		input_command = strtok(line, delimiter);

		while(input_command != NULL)
		{
			/*First handle the inbuilt command internally */

			/* if not we initialize new process to handle the path */
			pid_t child_pid = fork();

			if (child_pid == -1)
			{
				perror("fork failed");
				exit(-1);
			}
			else if (child_pid == 0) /* child process */
			{
				char *path_command(input_path); /* call the path function */
				if (path_command == NULL)
				{
					perror("command not found");
					exit(1);
				}
				execve(path_command, &input_command, __environ);
				if (execve(path_command, &input_command, __environ) == -1)
				{
					perror("failed to execute command");
					exit(EXIT_FAILURE);
				}
			}
			else if (child_pid > 0)
			{
				int status;

				waitpid(child_pid, &status. 0);
				if (WIFEXITED(status) && WEXISTATUS(status) != 0)
				{
					printf("Child process %d exited with status %d\n", child_pid, WEXISTATUS(status));
				}
			}
			input_command = strtok(line, delimiter);
		}
		return (0);
	}
}