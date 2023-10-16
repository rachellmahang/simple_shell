#include "shell.h"

/**
  * fetch_toks - tokenizes a string
  * @tok_string: string to be tokenized
  * @delim: char * of delimiters
  * Return: char **, argument vector to be used in execve or other
  */
char **fetch_tokens(char *tok_string, char *delim)
{
	char *tok = NULL;
	char **toks;
	char *tempvar = NULL;
	size_t cnt = 0;

	tempvar = _strdup(tok_string);
	if (!tempvar)
		return (NULL);
	tok = _strtok(tempvar, delim);
	while (tok)
	{
		cnt++;
		tok = _strtok(NULL, delim);
	}
	free(tempvar);
	toks = malloc(sizeof(char *) * (cnt + 1));
	if (!toks)
		return (NULL);

	tok = _strtok(tok_str, delim);
	for (cnt = 0; tok; cnt++)
	{
		toks[cnt] = tok;
		tok = _strtok(NULL, delim);
	}
	toks[cnt] = NULL;
	return (toks);
}
