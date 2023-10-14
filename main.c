#include "main.h"
/**
 * main - The main function to read use input
 * Return: 0 on success
 */
int main(__attribute__((unused)) int argc, char *argv[])
{
	int char_read;

	size_t len = 0;

	char *token;

	char *line = NULL;

	char *delimiter = " \n";

	char *command_arguments[1024];

	int _index = 0;

	while(1)
	{
		write(1, "MyShell$ ", 9);
		char_read = getline(&line, &len, stdin);
		if (char_read == -1)
		{
			/* Handle the CTRL + D */
			if (feof(stdin))
			{
				/*include builtin exit comman */
				exit_builtin()
			}
			else
			{
				perror("Error reading input\n");
				exit(-1)
			}
		}
		else if (character_read == 1)
		{
			continue;
		}
		else
		{
			tokenization(token);
			else
			{
				_pid();
			}
		}
		/*Our loops ends here */
	}
	free(line);
	return (0);
}
