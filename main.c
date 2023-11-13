#include "main.h"

/**
 * main - Simple Shell main function
 * @ac: Count of arguments
 * @av: Arguments
 * Return: 0 Always (success)
*/
int main(int ac, char **argv)
{
    char *line = NULL, **cmd = NULL;
    /*char **cmd = NULL;*/
    int sts = 0, i;
    (void) ac;
    (void) argv;

    while (1)
    {
        line = rdg_line();
        if (line == NULL) /* Reach EOF CTRL + D*/
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            return (sts);
        }

        cmd = tokenizer(line);
        if (!cmd)
            continue;

        for (i = 0; cmd[i]; i++)
        {
            printf("%s\n", cmd[i]);
            free(cmd[i]), cmd[i] = NULL;
        }
        free(cmd), cmd = NULL;


        /*sts = execute_cmd(cmd, argv);*/
    }
}