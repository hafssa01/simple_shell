#include "main.h"

int execute_cmd(char **cmd, char **argv)
{
        pid_t child;
        int sts;

        child = fork();
        if (child == 0)
        {
                if (execve(cmd[0], cmd, environ) == -1)
                {
                        perror(argv[0]);
                        free2Dary(cmd);
                        exit(0);
                }
        }
        else
        {
                waitpid(child, &sts, 0);
                free2Dary(cmd);
        }
        return (WEXITSTATUS(sts));
}