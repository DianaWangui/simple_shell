#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

void exec_command(const char *command);
char *get_path_check(char *command);

#endif /* MAIN_H */
