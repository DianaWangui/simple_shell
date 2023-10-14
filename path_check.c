#include "main.h"
/**
 * get_path_check - a function that checks for the path
 * @command: The command to be checked in the path
 * Return: NULL
*/
char *get_path_check(const char *command)
{
	char *path = getenv("PATH");
	char *copy_path = strdup(path);
	char command_path[1024];
	char *directory = strtok(copy_path, ":");

	/* this loops through and concatemate the paths */
	while(directory != NULL)
	{
		strcpy(command_path, dir);
		if (command_path[strlen(command_path)- 1] != '/')
		{
			strcat(command_path, "/");
		}
		strcat(command_path, command);
		if (access(command_path, F_OK) == 0 && access(command_path, X-OK) == 0)
		{
			free(path_copy);
			return(strdup(command_path));
		}
		dir = strtok(NULL, ":");
	}
	/*printf('File not found');*/
	free(path_copy);
	/* Returns the command if there was no execuatble path found */
	return (command);
}
