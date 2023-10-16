#include "main.h"
/**
 * exit_builtin - a fucntion to exit shell
 * exits with 0 status for success exit
 */
void exit_builtin(void)
{
	write(1, "Exiting Myshell...\n\n", 18);
	/* Make it sleep for 1.5 secs before exiting */
	sleep(1.5);
	exit(0);
}
/**
 * cd_builtin - A function for changing directory
 * @arg: The argument passed to the cd
 */
void cd_builtin(char *arg)
{
	char *home;

	if (arg == NULL)
	{
		home = getenv("HOME");
		if (home == NULL)
		{
			perror("cd: HOME environment is not set yet\n");
		}
		else
		{
			if (chdir(home) != 0)
			{
				perror("Could not change the Directory");
			}
		}
	}
	else
	{
		if (chdir(arg) != 0)
		{
			perror("Could not change the Director");
		}
	}
}
/**
 * env_builtin - a fucntion that prints the environment
 *
 */
void env_builtin(void)
{
	char **environ;
	char *env;
	int read;

	if (environ == NULL)
	{
		perror("Error: Unable to retieve environment variables");
		exit (-1);
	}
	for (env = environ; *env; env++)
	{
		if (*env == NULL)
		{
			continue;
		}
		read = write(STDOUT_FILENO, *env, strlen(*env));
		if (read == -1)
		{
			perror("Error writing environment variable");
			exit (EXIT_FAILURE);
		}
		if (write(STDOUT_FILENO, "\n", 1) == -1)
		{
			perror("Error writing new line character");
			exit(EXIT_FAILURE);
		}
	}
	exit(EXIT_SUCCESS);
}
