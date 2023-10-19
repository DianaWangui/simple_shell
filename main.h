#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

char *get_path_check(char *command);
extern char **environ;
extern char *token;
extern char *line;
extern char *delimiters;
extern char *command_arguments[];
/* Builtin prototypees */
void signal_handler(int signal);
void exit_builtin(void);
void cd_builtin(char *arg);
/*other helping functions */
int stringmp(const char *string1, const char *string2);
char *stringcat(char *destination, char *sourc);
size_t stringlength(const char *string);
int tokenization(char *line);
int _pid(char *command_arguments[]);
void env_builtin(void);
void error_message(char *command);
#endif /* MAIN_H */
