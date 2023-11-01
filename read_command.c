#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * read_command - Reads a command from the user.
 *
 * Return: A pointer to the command string.
 */
char *read_command(void)
{
    char *command = NULL;
    size_t bufsize = 0;

    if (getline(&command, &bufsize, stdin) == -1)
    {
        free(command);
        return NULL;
    }

    return command;
}

