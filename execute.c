#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * execute_command - Executes a command.
 *
 * @command: The command string.
 */
void execute_command(char *command)
{
    int i;
    pid_t pid;
    char **args = tokenize_input(command);
    char error_message[] = "Error\n";


    if (args == NULL || args[0] == NULL)
    {
        char error_message[] = "Error: Empty command\n";
        write(STDERR_FILENO, error_message, my_strlen(error_message));
        return;
    }

    pid = fork();

    if (pid == 0)
    {
        execve(args[0], args, NULL);
        write(STDERR_FILENO, error_message, my_strlen(error_message));
        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {
        wait(NULL);
    }
    else
    {
        char error_message[] = "Fork failed\n";
        write(STDERR_FILENO, error_message, my_strlen(error_message));
    }

    for (i = 0; args[i] != NULL; i++)
    {
        free(args[i]);
    }
    free(args);
}

