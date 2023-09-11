#include "main.h"

/*int Getting_a_Line(char **line, );*/
int main(void)
{
        char **argv;
        int i = 0;
        int loop = 0;
        size_t len;
        char *lineCopy;
        int lineCount;
        char *line = NULL;
        char *tokenized;
        char del[] = " ;:-|^><\n";

        while (loop == 0)
        {
                /* prompting */
                printf("enter a value\n");
                lineCount = getline(&line, &len, stdin);

                /* Error check */
                if (lineCount == -1)
                {
                        printf("Exiting shell......\n");
                        exit(EXIT_FAILURE);
                }

                /* Making duplicate */
                lineCopy = malloc(sizeof(char) * strlen(line));
                if (lineCopy == NULL)
                {
                        perror("memory allocation error");
                        return (-1);
                }
                strcpy(lineCopy, line);

                /* Getting the Arguments*/
                tokenized = strtok(lineCopy, del);
                argv = malloc(sizeof(char *) * lineCount);
                while (tokenized != NULL)
                {
                        argv[i] = malloc(sizeof(char) * strlen(tokenized));
                        strcpy(argv[i], tokenized);
                        tokenized = strtok(NULL, del);
                        i++;
                }

                /* executing the commands */
                if (execute_basic(argv) == -1)
                {
                        for (i = 0; argv[i] != NULL; i++)
                        {
                                argv[i] = NULL;
                                free(argv[i]);
                        }
                        for (i = 0; argv[i] != NULL; i++)
                                printf("%d, %s\n", i, argv[i]);
                };

                free(lineCopy);
        }
        for (i = 0; argv[i] != NULL; i++)
                free(argv[i]);

        free(line);
        free(argv);

        return 0;
}