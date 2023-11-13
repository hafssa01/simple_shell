#include "main.h"

char *read_line(void)
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

char **tokenizer(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **cmd = NULL;
	int cnt = 0, i = 0;
	
	if (!line)
		return (NULL);
	
	tmp = _strdup(line);
	
	token = strtok(tmp, DELIM);
	
	if (token == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL); 
	}
	while (token)
	{
		cnt++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	cmd = malloc(sizeof(char *) * (cnt + 1));
	
	if (!cmd)
	{
		free(line), line = NULL;
		return (NULL);
	}
	
	token = strtok(line, DELIM);
	while (token)
	{
		cmd[i] = strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(line), line = NULL;
	cmd[i] = NULL;
	return (cmd);
}01~
