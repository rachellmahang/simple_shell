#include "simple.h"
/**
 * _realloc - realloc old ptr to new
 * @ptr: old one
 * @old_size: old size of pointer
 * @new_size: new size of pointer
 * Return: as mentioned
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int r;
	char *firstpointer;

	if (old_size == new_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	firstpointer = malloc(sizeof(char) * new_size);
	if (firstpointer == NULL)
		return (NULL);
	if (ptr)
	{
		for (r = 0; r < old_size; r++)
		{
			firstpointer[r] = *((char *)ptr + r);
		}
	}
	free(ptr);
	return (firstpointer);
}

/**
 *_atoi - converts an str to an integer
 *@s: the str to be converted
 *Return: 0 if no numbers in str, converted number otherwise
 */
int _atoi(char *l)
{
	int r, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (r = 0;  l[r] != '\0' && flag != 2; r++)
	{
		if (l[r] == '-')
			sign *= -1;

		if (l[r] >= '0' && l[r] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (l[r] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

/**
 * _strlen - count the number of characters in a string
 * @str: pointer to a string
 *
 * Return: number of characters in the string
 */
int _strlen(char *rst)
{
	int cnt = 0;

	while (*(rst + cnt))
		cnt++;

	return (cnt);
}

/**
 * _strdup - malloc new str and copy *str into it
 * @str: the string we copy
 * Return: pointer to new string
 */
char *_strdup(char *rst)
{
	unsigned int r;
	int cnt = 0;
	char *destin;

	if (rst == NULL)
		return (NULL);
	for (r = 0; rst[r]; r++)
	{
		cnt++;
	}
	cnt += 1;
	destin = malloc(cnt * sizeof(char));
	if (destin == NULL)
	{
		return (NULL);
	}
	for (r = 0; rst[r] != '\0'; r++)
	{
		destin[r] = rst[r];
	}
	destin[r] = rst[r];
	return (destin);
}

/**
  * _strcmp - a function to compare 2 strings
  * @s1: the first string
  * @s2: the second string
  *
  * Return: int
  */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
		break;
	}
	return (*s1 - *s2);
}
