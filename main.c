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
    int sts = 0, idx = 0;
    (void) ac;


    while (1)
    {
        line = read_line();
        if (line == NULL) /* Reach EOF CTRL + D*/
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            return (sts);
        }
        idx++;
        
        cmd = tokenizer(line);
        if (!cmd)
            continue;

        sts = execute_cmd(cmd, argv, idx); /*Execute line*/

    }
}
