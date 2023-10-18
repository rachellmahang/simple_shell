#include "simple.h"

/**
 * task2 - a function that is executable
 * @becca: is the pointer
 * Author: rachel and rebecca
 */

void task2(const char *becca)
{
	pid_t kid = fork();

	if (kid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (kid == 0)
	{
		execlp(becca, becca, (char *)NULL);

		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
