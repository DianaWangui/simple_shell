#include "main.h"
/**
 * error_message - a function to print the error message
 * @command: The command passed
 * exit with status failure
 */
void error_message(char *command)
{
	char *first_error;

	char *second_error;

	first_error = "Command '";
	write(STDERR_FILENO, first_error, strlen(first_error));
	write(STDERR_FILENO, command, strlen(command));
	second_error = "' not found\n";
	write(STDERR_FILENO, second_error, strlen(second_error));
	exit(EXIT_FAILURE);
}
