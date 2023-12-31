
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>

#define DELIM " \t\n"
extern char **environ;

char *_getpath(char *cmd);
char *_getenv(char *var);
int execute_cmd(char **cmd, char **argv, int idx);
char *read_line(void);
char **tokenizer(char *line);

char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

void print_error(char *name, char *cmd, int idx)
void free2Dary(char **arr);
char *_itoa(int n);
void rvrs_str(char *str, int len);


#endif
