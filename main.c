#include "main.h"
/**
 * main - The main function to read use input
 * Return: 0 on success
 */
int main(void)
{
	int char_read;

	size_t len = 0;

	char *line = malloc(1024);

	while (1)
	{
		write(1, "MyShell$ ", 10);
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
		}
	}
	free(line);
	return (0);
}
