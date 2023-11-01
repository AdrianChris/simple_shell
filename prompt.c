#include "main.h"
#include <unistd.h>

/**
 * display_prompt - Displays a shell prompt.
 */
void display_prompt(void)
{
    write(STDOUT_FILENO, "$ ", 2);
}

