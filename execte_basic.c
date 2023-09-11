#include "main.h"

int execute_basic(char *argv[])
{
        if (fork() == 0)
        {
                /* executing the commands */
                if (execve(argv[0], argv, NULL) == -1)
                {
                        perror("File execution error");
                        return (-1);
                }
        }else{
                wait(NULL);
        }

        return (0);
}