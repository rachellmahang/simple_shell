#include "simple.h"

/**
  * comments_r - removes comments from a string
  * @rst: string to have comment surgery
  */
void comments_r(char *rst)
{
	char *rem = _strchr(rst, '#');

	if (rem)
		*rem = '\0';
}
