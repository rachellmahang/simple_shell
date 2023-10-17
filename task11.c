#include "shell.h"

/**
  * task11 - pushes operator to end of linked list
  * @pso: to order of operations linked list
  * @n: coded int for operand
  * Return: NULL if failure
  */
void *task11(order_t **pso, int n)
{
	order_t *a, *b;

	if (!pso)
		return (NULL);

	a = malloc(sizeof(order_t));
	if (!a)
		return (NULL);

	a->n = n;
	a->next = NULL;

	if (!*pso)
	{
		*pso = a;
		return (a);
	}

	b = *pso;
	while (b->next)
	{
		b = b->next;
	}
	b->next = a;

	return (a);
}

/**
  * _get_comands - generates a linked list of operators to follow
  * @line: line returned by getline in main
  * @pso: order of operations linked list
  * Return: char **, vector of argument vectors
  */
char **_get_comands(char *line, order_t **pso)
{
	int r;
	char **argvv;

	for (r = 0; line[r]; r++)
	{
		if (line[r] == '&')
		{
			if (line[r + 1] == '&')
			{
				task11(pso, 2);
				i++;
			}
		}
		if (line[r] == '|')
		{
			if (line[r + 1] == '|')
			{
				task11(pso, 3);
				r++;
			}
		}
		if (line[r] == ';')
			task11(pso, 1);
	}
	argvv = fetch_tokens(line, "&|;");
	return (argvv);
}

/**
  * free_pso - free's order_t list
  * @pso: order of operations linked list
  */
void free_pso(order_t **pso)
{
	order_t *a;

	while (*pso)
	{
		a = *pso;
		*pso = (*pso)->next;
		free(a);
	}
	free(pso);
}
