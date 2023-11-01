#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * main - Entry point of the shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *command;
    char newline = '\n';

    while (1)
    {
        display_prompt();
        command = read_command();

        if (command == NULL)
        {
            char newline = '\n';
            write(STDOUT_FILENO, &newline, 1);
            break;
        }

        execute_command(command);
        free(command);

        write(STDOUT_FILENO, &newline, 1);
    }

    return 0;
}

