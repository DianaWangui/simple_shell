#include "main.h"
void signal_handler(int signal);
/**
 * main - The main function to read user input
 * @argc: argument count
 * @argv: array of argument string
 * Return: 0 on success
 */
int main(char argc, char *argv[])
{
	FILE *file;
	int char_read;
	int char_write = 0;
	char *prompt = "$ ";
	size_t len = 0;
	char *line = NULL;
	int is_interactive = isatty(STDIN_FILENO);

	signal(SIGINT, signal_handler);
	if (argc > 1)
	{
		for (i = 0; i < argc; i++)
		{
			file = fopen(argv[i], "r");
			if (file == NULL)
			{
				perror("Error opening file");
				continue;
			}
			while ((char_read = getline(&line, &len, file)) != -1)
			{
				if (char_read > 1)
					tokenization(line);
			}
		}
		fclose(file);
	}
	else
	{

	while (1)
	{
		if (is_interactive)
		{
			char_write = write(1, prompt, strlen(prompt));
			if (char_write == -1)
			{
				perror("Write error");
				free(line);
				exit(1);
			}
		}
		fflush(stdout);
		char_read = getline(&line, &len, stdin);
		if (char_read == -1)
		{
			if (feof(stdin))
			{
				free(line);
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
	}
	free(line);
	return (0);
}
