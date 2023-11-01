#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * my_strdup - Duplicates a string.
 *
 * @str: The string to duplicate.
 * Return: A pointer to the duplicated string.
 */
char *my_strdup(const char *str)
{
    char *new_str = malloc(my_strlen(str) + 1);

    if (new_str == NULL)
    {
        perror("Allocation error");
        exit(EXIT_FAILURE);
    }

    my_strcpy(new_str, str);

    return new_str;
}

/**
 * my_strlen - Calculates the length of a string.
 *
 * @str: The input string.
 * Return: The length of the string.
 */
size_t my_strlen(const char *str)
{
    const char *s = str;
    while (*s)
        ++s;
    return (size_t)(s - str);
}

/**
 * my_strcpy - Copies a string.
 *
 * @dest: The destination string.
 * @src: The source string.
 * Return: A pointer to the destination string.
 */
char *my_strcpy(char *dest, const char *src)
{
    char *d = dest;
    const char *s = src;
    while ((*d++ = *s++))
        ;
    return dest;
}

