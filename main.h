#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

void exec_command(const char *command);
char *get_path_check(const char *__path, char *const argv[]);

/*Builtin prototypes */

void exit_builtin(void);
void cd_builtin(char *arg);
/*other helping functions */

int tokenization(char *token);
int _pid(void);
void error_message(char *command);
#endif /* MAIN_H */
