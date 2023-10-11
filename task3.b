#include "simple.h"

/**
 * main - a function for tokenization
 * Return: as mentioned
 * Author: rebecca and rachel
 */
int main()
{
	char command[] = " ";
	char buffer[256];

	char *token;
	char *delimitor = ",";

	token = strtok(command, delimitor);

	while (token != NULL)
	{
		sprintf(buffer, "becca: %s\n", token);
		printr(buffer, STDOUT_FILENO);
		token = strtok(NULL, delimitor);
	}
	return (0);
}
