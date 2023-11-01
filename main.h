#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#define BUF_SIZE 1024

/* Function Declarations */
void display_prompt(void);
char *read_command(void);
void execute_command(char *command);
char **tokenize_input(char *input);
char *my_strdup(const char *str);
size_t my_strlen(const char *str);
char *my_strcpy(char *dest, const char *src);



#endif /* MAIN_H */

