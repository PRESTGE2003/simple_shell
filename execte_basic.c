#include "main.h"

int execute_basic(char *argv[])
{
        /* executing the commands */
        if (execve(argv[0], argv, NULL) == -1)
        {
                perror("File execution error");
                return (-1);
        }

        return (0);
}