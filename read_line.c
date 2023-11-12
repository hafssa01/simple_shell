#include "main.h"

char *rdg_line(void)
{
    char *l = NULL;
    size_t ln = 0;
    ssize_t rc;

    if (isatty(STDIN_FILENO))
    write(STDOUT_FILENO, "$ ", 2); /*Showe the prompt first*/
    
    
    rc = getline(&l, &ln, stdin);
    if (rc == -1) 
    {
        return (NULL);
    }

    return (l);
}