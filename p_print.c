#include "main.h"

void p_print (const char*text)
{
write(STDOUT_FILENO, &text, strlen(text));
}
