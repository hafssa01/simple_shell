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
    int sts = 0;
    (void) ac;
if (isatty(STDIN_FILENO)){
   while (1)
    {
        line = read_line();
        if (line == NULL) /* Reach EOF CTRL + D*/
        {
            write(STDOUT_FILENO, "\n", 1);
            return (sts);
        }
	    execute();
    }
}    
 cmd = tokenizer(line);
        if (!cmd)
            continue;

<<<<<<< HEAD


        sts = execute_cmd(cmd, argv); /*Execute line*/

=======
        for (i = 0; cmd
			[i]; i++)
        {
            printf("%s\n", cmd[i]);
            free(cmd[i]), cmd[i] = NULL;
        }
        free(cmd), cmd = NULL;

>>>>>>> 340cbdef06cbc9a685a6818105bb146e1ab57506
    }
}
