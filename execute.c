#include "main.h"

void execute_cmd(const char *cmd) {
pid_t child, wpid;
int status;

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
int exist_stat = WIFEXITED(status);
p_print(exist_stat);
}
else if (WIFSIGNALED(status))
{
int signal_ = WIFSIGNALED(status);
p_print(signal_);
}
}
}
