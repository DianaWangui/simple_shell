#include "main.h"
/**
 * main - The main function to read user input
 * Return: 0 on success
 */
int main(void)
{
	int char_read;
	int char_write = 0;
	char *prompt = "$ ";
	size_t len = 0;
	char *line = NULL;
	int is_interactive = isatty(STDIN_FILENO);
	signal(SIGINT, signal_handler);

	while (1)
	{
		if (is_interactive)
		{
			char_write = write(1, prompt, strlen(prompt));
			if (char_write == -1)
			{
				perror("Write error");
				exit(1);
			}
		}
		fflush(stdout);
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
				if (is_interactive)
				{
					free(line);
				}
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
