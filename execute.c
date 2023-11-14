#include "main.h"

int execute_cmd(char **cmd, char **argv)
{
        pid_t child;
        int sts;

<<<<<<< HEAD
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
=======
    child = fork();
    switch (child)
    {
    case 0:
        execlp(cmd, cmd, (char *)NULL);
        perror("unsuccessful");
        exit(EXIT_FAILURE);
    case -1:
        perror("unsuccessful");
    default:
        waitpid(child, &status, 0);

    if(WIFEXITED(status))
    {
        int exit_stat = WIFEXITED(status);
        printf("%d", exit_stat);
    }
    else if (WIFSIGNALED(status))
    {
        int signal_ = WIFSIGNALED(status);
        printf("%d", signal_);
    }
    } 
}       
>>>>>>> 340cbdef06cbc9a685a6818105bb146e1ab57506
