#include "main.h"

/**
 * main - Simple Shell main function
 * @ac: Count of arguments
 * @av: Arguments
 * Return: 0 Always (success)
*/
int main(void) {
    char *cmd;
if(isatty(STDIN_FILENO))
{
<<<<<<< HEAD
    char *line = NULL, **cmd = NULL;
    int sts = 0, idx = 0;
    (void) ac;
=======
 while(1) {
        printf("M&H-$ ");
        cmd = read_line();
>>>>>>> 9597fd9f867579baeaf1b0951d63b6140fcba150

        if (cmd != NULL) {
            execute(cmd);
            free(cmd);
        }
<<<<<<< HEAD
        idx++;
        
        cmd = tokenizer(line);
        if (!cmd)
            continue;

        sts = execute_cmd(cmd, argv, idx); /*Execute line*/

    }
=======
    } 
}
    return EXIT_SUCCESS;
>>>>>>> 9597fd9f867579baeaf1b0951d63b6140fcba150
}
