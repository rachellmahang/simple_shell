#include "simple.h"

/**
  * *_strcpy - copies the string pointed
  *to by source, including the terminating null byte
  *to the buffer pointed to by destin
  * @destin: points to buffer
  * @source: points to string
  *
  * Return: pointer
  */
char *_strcpy(char *destin, char *source)
{
	char *response  = destin;

	while (*source)
	{
		*destin = *source;
		destin++;
		source++;
	}
	*destin = '\0';
return (response);
}

/**
  * *_strcat - a function to concatenate 2 strings
  * @destin: what we are apprending to
  * @source: the string we are appending from
  * Return: char
  */
char *_strcat(char *destin, char *source)
{
	char *begin = destin;

	while (*destin)
		destin++;
	while (*source)
	{
		*destin = *source;
		source++;
		destin++;
	}
	*destin = '\0';
	return (begin);
}

/**
  * _strchr - locates a character
  * @l: the string we look thru
  * @y: the character we look for
  * Return: a pointer to the char or NULL
  */
char *_strchr(char *l, char y)
{
	if (l == NULL)
		return (NULL);
	for (; *l; l++)
	{
		if (*l == y)
			return (l);
	}
	if (*l == y)
	{
		return (l);
	}
	return (NULL);
}
/**
 * do_something - a dummy function
 * @something: a dummy integer
 */
void do_something(__attribute__((unused))int something)
{
	_putchar('\n');
	puts_prompt();
}
