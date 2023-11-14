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
 while(1) {
        printf("M&H-$ ");
        cmd = read_line();

        if (cmd != NULL) {
            execute(cmd);
            free(cmd);
        }
    } 
}
    return EXIT_SUCCESS;
}
