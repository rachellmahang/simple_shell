#include "simple.h"
/**
 * strtok - tokenizes the rst
 * @buffer: the string
 * @delim: the dividing char
 * Return: char * to token or NULL
 */
char *_strtok(char *buffer, const char *delim)
{
	static char *ps;
	char *k;
	int r = 0;
	int stop = 0;
	int letter = 0;

	if (buffer)
		ps = buffer;
	k = ps;
	while (ps && *ps)
	{
		while (delim[r])
		{
			if (*ps == delim[r] && letter == 0)
			{
				++k;
				++ps;
				k = 0;
				continue;
			}
			if (*ps == delim[r] && letter == 1)
			{
				*ps++ = '\0';
				stop = 1;
				r = 0;
				break;
			}
			++r;
		}
		if (stop || !*ps)
			break;
		letter = 1;
		r = 0;
		++ps;
	}
	if (!k || *k == '\0')
		return (NULL);
	return (k);
}
