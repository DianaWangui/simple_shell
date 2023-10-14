#include "main.h"
/**
 * main - The main function to read use input
 * Return: 0 on success
 */
int main(void)
{
	int char_read;

	size_t len = 0;

	/*char *token; */

	char *line;


	while(1)
	{
		/* printf(YEsss);*/
		write(1, "MyShell$ ", 10);
		char_read = getline(&line, &len, stdin);
		printf("checking input character\n");
		printf("%s\n", line);
		if (char_read == -1)
		{
			printf("If character is null\n");
			/* Handle the CTRL + D */
			if (feof(stdin))
			{
				/*include builtin exit comman */
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
		/*Our loops ends here */
	}
	free(line);
	return (0);
}
