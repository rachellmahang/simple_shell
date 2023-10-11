#include "simple.h"

/**
 * printr - a function that print
 * @becca: is the pointer
 * @rae: is the input
 * Author: rebecca and rachel
 */

void printr(char *becca, int rae)
{

	int r = 0;

	for (; becca[r] != '\0'; r++)
		write(rae, &becca[r], 1);
}
