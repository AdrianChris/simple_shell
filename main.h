#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE
#define DELIM " \t\n"
#define BUF_SIZE 1024
#define INITIAL_BUFFER_SIZE 1024
#define MAX_INPUT_LENGTH 1024

extern char **environ;

#include <stdbool.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

bool is_builtin(const char *cmds);
void handle_builtin(char **cmds, char **argv, int *sts, int idx);
void exit_shell(char **cmds, char **argv, int *sts, int idx);
void print_env(char **cmds, int *sts);
int my_atoi(char *str);
bool is_positive_num(const char* str);

char *get_input(void);
char **tokenizer(char *j);
void free_str(char **arr);
int _execute(char **cmd, char **argv, int idx);

/* Tools */

void my_error(char *str, char *nm, int idx);
int my_getchar(void);
char *_getenv(char *variable);
char *my_itoa(int n);
char *my_strcat(char *dt, char *src);
char *my_strdup(const char *str);
int my_strcmp(const char *s1, const char *s2);
char *my_strcpy(char *dstn, const char *src);
int my_strlen(const char *s);
void reverse_str(char *str, int len);
char *get_path(char *command);
int my_sprintf(char *outbuf, const char *fmt, ...);
int custom_snpt(char *str, size_t size, const char *format, ...);
void handle_character(char *outbuf, int *written, const char **fmt);
void handle_integer(char *outbuf, int *written,
					va_list *args, const char **fmt);
void handle_string(char *outbuf, int *written,
				   va_list *args, const char **fmt);
int my_sprintf(char *outbuf, const char *fmt, ...);

#endif
