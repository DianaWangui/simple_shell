#include "main.h"

/**
 * get_path_check - a function that checks for the path
 * @command: The command to be checked in the path
 * Return: NULL
*/
char *get_path_check(char *com)
{
    char *path = getenv("PATH");

    char *copy_path = strdup(path);

    char *directory = strtok(copy_path, ":");

    while(directory != NULL)
    {
        char *whole_path = malloc(strlen(directory) + strlen(com) + 2);
        sprintf(whole_path, "%s/%s", directory, com);

        printf("Whole path is %s", whole_path);
        if (access(whole_path, X_OK) == 0)
        {
            free(copy_path);
            return (whole_path);
        }
        free(whole_path);
        directory = strtok(NULL, ":");
    }
    free(copy_path);
    return(NULL);
}
