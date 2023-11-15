#include "main.h"

int execute_cmd(char **cmd, char **argv, int idx)
{
        char *full_cmd;
        pid_t child;
        int sts;

        full_cmd = _getpath(cmd[0]);
        if (!full_cmd)
        {
                print_error(argv[0], cmd[0], idx);
                free2Dary(cmd);
                return(127);
        } 

        child = fork();
        if (child == 0)
        {
                if (execve(full_cmd, cmd, environ) == -1)
                {
                        free(full_cmd), full_cmd = NULL;
                        free2Dary(cmd);
                 
                }
        }
        else
        {
                waitpid(child, &sts, 0);
                free2Dary(cmd);
                free(full_cmd), full_cmd = NULL;
                
        }
        return (WEXITSTATUS(sts));
}

