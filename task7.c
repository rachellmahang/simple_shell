#include "simple.h"

/**
  * _initenvs_list - initialize a env_list
  * Return: env_list_t **, new list formed
  */
env_list_t **_initenvs_list(void)
{
	env_list_t **env = malloc(sizeof(env_list_t *));
	env_list_t *first = NULL;
	env_list_t *n_env = NULL;
	char *tok;
	int var_cnt = 0;

	for (var_cnt = 0; environ[var_cnt]; var_cnt++)
	{
		n_env = malloc(sizeof(env_list_t));
		if (first)
			first->next = n_env;
		tok = _strdup(_strtok(environ[var_cnt], "="));
		n_env->name = tok;
		tok = _strdup(_strtok(NULL, " "));
		n_env->value = tok;
		n_env->next = NULL;
		first= n_env;
		if (var_cnt == 0)
			*env = first;
	}

	return (env);
}

/**
  * printenvs_list - prints a env_list
  * @env: environment linked list
  */
void printenvs_list(env_list_t **env)
{
	env_list_t *r = *env;

	while (r != NULL)
	{
		_puts(r->name);
		_puts("=");
		_puts(r->value);
		_puts("\n");
		r = r->next;
	}
}

/**
  * free_env_list_node - free's an env_list node
  * @node: env_list node to be free'd
  */
void free_env_list_node(env_list_t *node)
{
	free(node->name);
	free(node->value);
	free(node);
}

/**
  * frees_env_list - free's an env_list list
  * @env: environment linked list
  */
void frees_env_list(env_list_t **env)
{
	env_list_t *tempvar;

	while (*env)
	{
		tempvar = *env;
		*env = (*env)->next;
		free_env_l_node(tempvar);
	}
	free(env);
}
