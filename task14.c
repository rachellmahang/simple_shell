#include "simple.h"

/**
  * task14 - free's char * arrays
  * @argv: argument vector
  */
void task14(char **argv)
{
	int r;

	for (r = 0; argv[r]; r++)
	{
		free(argv[r]);
	}
	free(argv);
}
