#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * tokenize_input - Tokenizes a string into an array of tokens.
 *
 * @input: The input string to tokenize.
 * Return: An array of tokens.
 */
char **tokenize_input(char *input)
{
    int bufsize = BUF_SIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        perror("Allocation error");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, " \t\n");

    while (token != NULL)
    {
        tokens[position] = my_strdup(token);

        if (!tokens[position])
        {
            perror("Allocation error");
            exit(EXIT_FAILURE);
        }

        position++;

        if (position >= bufsize)
        {
            bufsize += BUF_SIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                perror("Reallocation error");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " \t\n");
    }
    tokens[position] = NULL;

    return tokens;
}

