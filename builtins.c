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
	char *env_var;
	char *value;
	int i = 0;

	while ((env_var = environ[i]) != NULL)
	{
		value = getenv(env_var);
		if (value != NULL)
		{
			write(STDOUT_FILENO, env_var, strlen(env_var));
			write(STDOUT_FILENO, "=", 1);
			write(STDOUT_FILENO, value, strlen(value));
			write(STDOUT_FILENO, "\n", 1);
		}
		i++;
	}
}
