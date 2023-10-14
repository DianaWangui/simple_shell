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

	char *line = malloc(1024);


	while(1)
	{
		/* printf(YEsss);*/
		write(1, "MyShell$ ", 10);
		char_read = getline(&line, &len, stdin);
		printf("checking input character\n");
		printf("You entered the command: %s\n", line);
		printf("charactes read are:  %d\n", char_read);
		if (char_read == -1)
		{
			/* Handle the CTRL + D */
			if (feof(stdin))
			{
				printf("You just pressed ctrl d\n");
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
			printf("am still here");
			tokenization(line);
			free(line);
		}
		/*Our loops ends here */
	}
	free(line);
	return (0);
}
