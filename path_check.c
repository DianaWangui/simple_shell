#include "main.h"
/**
 * get_path_check - a function to check for the path
 * @command: The command to be checked in the path
 * Return: NULL
*/
char *get_path_check(const char *command, char *const argv[])
{
	char *path = getenv("PATH");

	char copy_path = strdup(pat);

	char *directory = strtok(copy_path, ":");

	if (path == NULL)
	{
		perror("PATH not set");
		exit(-1);
	}
	if (copy_path == NULL)
	{
		perror("Failed to copy path");
		exit(-1);
	}
	while(directory != NULL)
	{
		char *whole_path = malloc(strlen(directory) + strlen(command) + 2);

		if (whole_path == NULL)
		{
			perror("Failed to allocate memory to whole path");
			free(copy_path);
			exit(-1);
		}
		sprintf(whole_path, "%s/%s", directory, command);
		printf("Whole path is, %s\n", whole_path);
		if (access(whole_path, X_OK) == 0)
		{
			free(copy_path);
			return (whole_path);
		}
		free(whole_path);
		directory = strtok(NULL, ":");
	}
	free(copy_path);
	return (0);
}
