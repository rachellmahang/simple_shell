#include "simple.h"

/**
  * fetch_tokens - tokenizes a string
  * @tok_string: string to be tokenized
  * @delim: char * of delimiters
  * Return: char **, argument vector to be used in execve or other
  */

char **fetch_tokens(char *tok_string, char *delim)
{
	char *tok = NULL;
        char *tempvar = NULL
	size_t cnt = 0;
	char **toks = malloc(sizeof(char *) * (cnt + 1));

        tempvar = _strdup(tok_string);

        if (!tempvar)
                return (NULL);
        tok = strtok(tempvar, delim);

        while (tok)
        {
                cnt++;
		tok = strtok(NULL, delim);
        }
        free(tempvar);
        if (!toks)
                return (NULL);

        for (cnt = 0; tok; cnt++)
        {
	 	toks[cnt] = tok;
                tok = strtok(NULL, delim);
        }
        toks[cnt] = NULL;

        return toks;
}
