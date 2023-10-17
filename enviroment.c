#include "main.h"
/**
 * env_builtin - a fucntion that prints the environment
 *
 */
void env_builtin(void)
{
        char *var;
        char *value;
        int i;
        /*size_t len; */

        for (i = 0; environ[i] != NULL; i++)
        {
                var = environ[i];
                value = strchr(var, '=');
                if (value != NULL)
                {
                        /* len = value - var; */
                        if (write(STDOUT_FILENO, environ[i], strlen(environ[i])) == -1 || write(STDOUT_FILENO, "\n", 1) == -1)
                        {
                                perror("Error reading environment variable");
                                exit(EXIT_FAILURE);
                        }
                }
        }
        exit(EXIT_SUCCESS);
}