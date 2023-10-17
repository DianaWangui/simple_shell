#include "main.h"
/**
 * get_path_check - a function to check for the path
 * @command: The command to be checked in the path
 * Return: NULL
*/
char *get_path_check(char *command)
{
	char *path = getenv("PATH");
	char *copy_path = strdup(path);
	char command_path[1024];
	char *directory = strtok(copy_path, ":");
	if (copy_path == NULL)
	{	perror("Failed");
		return (NULL);
	}
	while (directory != NULL)
	{
		strcpy(command_path, directory);
		if (command_path[strlen(command_path) - 1] != '/')
		{
			strcat(command_path, "/");
		}
		strcat(command_path, command);
		if (access(command_path, F_OK) == 0 && access(command_path, X_OK) == 0)
		{
			free(copy_path);
			return (strdup(command_path));
		}
		directory = strtok(NULL, ":");
	}
	/*printf('File not found');*/
	free(copy_path);
	/* Returns the command if there was no execuatble path found */
	return (command);
}
