#include "main.h"
#define MAX_INPUT_LENGTH 150
/**
 * main - The main function to read use input
 * Return: 0 on success
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
		printf("simple_shell$");
		if(fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\nExiting simple_shell.\n");
			break();
		}
		input[strcspn(input, "\n")] = '\0';
		exec_command(input);
	}
	return (0);
}
