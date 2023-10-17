#include "main.h"
/**
 * main - The main function to read user input
 * Return: 0 on success
 */
int main(void)
{
	int char_read;

	size_t len = 0;

	char *line = malloc(1024);

	int is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_interactive)
		{
			write(1, "$ ", 2);
		}
		char_read = getline(&line, &len, stdin);
		if (char_read == -1)
		{
			if (feof(stdin))
			{
				exit_builtin();
			}
			else
			{
				perror("Error reading input\n");
				free(line);
				exit(-1);
			}
		}
		else if (char_read == 1)
		{
			continue;
		}
		else
		{
			tokenization(line);
			free(line);
		}
	}
	free(line);
	return (0);
}
