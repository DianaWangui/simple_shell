#include "main.h"
/**
 * env_builtin - a fucntion that prints the environment
 *
 */
void env_builtin(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, "\n", 1);
	}
}
