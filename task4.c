#include "simple.h"

/**
 * main - an entry file
 * Return: as mentioned
 */
int main(void)
{
	char command[110];

	while (1)
	{
		task1();
		task5(command, sizeof(command));
		task2(command);
	}
	return (0);
}
