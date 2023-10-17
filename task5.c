#include "simple.h"

/**
 * task5 - user input
 * @becca: is the pointer
 * @size: is the byte
 * author: rebecca and rachel
 */

void task5(char *becca, size_t size)
{
	if (fgets(becca, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			_puts("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("fgets");
			exit(EXIT_FAILURE);
		}
	}
	becca[strcspn(becca, "\n")] = '\0';
}
