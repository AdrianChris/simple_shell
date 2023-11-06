#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE
#define DELIM " \t\n"
#define BUF_SIZE 1024
#define INITIAL_BUFFER_SIZE 1024
#define MAX_INPUT_LENGTH 1024


extern char **environ;

#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *get_input(void);
char *my_strdup(const char *str);
int my_strlen(char *s);
int my_strcmp(char *s1, char *s2);
char *my_strcat(char *dt, char *src);
char **tokenizer(char *tsr);
void free_str(char **arr);
int _execute(char **cmd, char **argv);


#endif
