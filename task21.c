#include "simple.h"

/**
 * _strtoken - tokenizes the str
 * @buffer: the string
 * @delim: the dividing char
 * Return: char ** to tokens or NULL
 */
char **_strtoken(char *buffer, const char *delim)
{
    char **tokens = malloc(128 * sizeof(char *));
    char *token;
    int i = 0;

    token = strtok(buffer, delim);
    while (token != NULL)
    {
        tokens[i] = token;
        i++;
        token = strtok(NULL, delim);
    }
    tokens[i] = NULL;

    return tokens;
}
