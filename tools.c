#include "main.h"

char *_strdup(const char *str)
{
    char *ptr;
    int i, len = 0;

    if (str == NULL)
        return (NULL);

    while (str[len])
    
        len++;
    
    ptr = malloc(sizeof(char) * (len + 1));
    if (ptr == NULL)
        return (NULL);
    for (i = 0; i<= len; i++)
        ptr[i] = str[i];
    return (ptr);
}

int _strcmp(char *s1, char *s2)
{
    int cnt;

    cnt = (int)*s1 - (int)*s2;
    while (*s1)
    {
        if (*s1 != *s2)
            break;
        s1++;
        s2++;
        cnt = (int)*s1 - (int)*s2;
    }
    return (cnt);
}

int _strlen(char *s)
{
    int len = 0;

    while (s[len])
        len++;
    return (len);
}

char *_strcat(char *dest, char *src)
{
    char *p = dest;

    while (*p)
        p++;

    while (*src)
    {
        *p = *src;
        p++;
        src++;
    }
    *p = *src;
    return (dest);
}

char *_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

void free2Dary(char **arr)
{
        int i;

        if (!arr)
                return;

        for (i = 0; arr[i]; i++)
        {
                free(arr[i]);
                arr[i] = NULL;
        }

        free(arr), arr = NULL;
}

void print_error(char *name, char *cmd, int idx)
{
    char *index, mssg[] = ": not found\n";

    index = _itoa(idx)

    write(STDERR_FILENO, name, _strlen(name));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, index, _strlen(index));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, _strlen(cmd));
    write(STDERR_FILENO, mssg, _strlen(mssg));

    free(index);

}

char *_itoa(int n)
{
    char buffer[20];
    int i = 0;

    if (n == 0)
        buffer[i++] = '0';
    else
    {
        while (n > 0)
        {
            buffer[i++] = (n % 10) + '0';
            n /= 10;
        }
    }

    buffer[i] = '\0';
    rvrs_str(buffer, i);

    return (_strdup(buffer));
}

void rvrs_str(char *str, int len)
{
    char tmp;
    int start = 0;
    int end = len -1;

    while (start < end)
    {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;    
    }
}