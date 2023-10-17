#include "shell.h"

/**
  * _getenv_list_value - get's a env_list node's value from a name
  * @name: char * to search for
  * @env: environment linked list
  * Return: char * containing nodes value
  */
char *_getenv_list_value(char *name, env_l_j **env)
{
	env_l_j *r = *env;

	while (r)
	{
		if (!_strcmp(name, r->name))
		{
			return (r->value);
		}
		r = r->next;
	}
	return (NULL);
}

/**
  * _getenv_l_node - get's a env_l node
  * @name: name to search for
  * @env: environment linked list
  * Return: env_l_j * node or NULL
  */
env_l_j *_getenv_l_node(char *name, env_l_j **env)
{
	env_l_j *r = *env;

	while (r)
	{
		if (!_strcmp(name, r->name))
		{
			return (r);
		}
		r = r->next;
	}
	return (NULL);
}

/**
  * _setenv_list - set environment variable in list
  * @argv: argument vector
  * @env: environment linked list
  */
void _setenv_list(char **argv, env_l_j **env)
{
	env_l_j *a, *b;

	if (!argv[1] || !argv[2])
		return;
	a = _getenv_l_node(argv[1], env);

	if (a)
	{
		free(a->value);
		a->value = _strdup(argv[2]);
		return;
	}

	a = *env;
	while (a->next)
	{
		a = a->next;
	}
	b = malloc(sizeof(env_l_j));
	b->name = _strdup(argv[1]);
	b->value = _strdup(argv[2]);
	b->next = NULL;
	a->next = b;
}


/**
  * _unsetenv_list - unset's a env_l var
  * @argv: argument vector
  * @env: environment linked list
  */
void _unsetenv_list(char **argv, env_l_j **env)
{
	env_l_j *a, *b;

	if (!argv[1])
		return;
	a = *env;
	b = *env;
	while (a)
	{
		if (!_strcmp(argv[1], a->name))
		{
			b->next = a->next;
			free_env_l_node(a);
			return;
		}
		b = a;
		a = a->next;
	}
}


/**
  * _get_str_env - converts linked list to str[] for execve
  * @env: environment linked list
  * Return: char **, a char *[] representation of env
  */
char **_get_str_env(env_l_j **env)
{
	env_l_j *a = *env;
	int cnt = 0, entry_len;
	char **string_env;
	char *entry;

	while (a)
	{
		cnt++;
		a = a->next;
	}

	str_env = malloc(sizeof(char *) * (cnt + 1));

	a = *env;
	cnt = 0;
	while (a)
	{
		entry_len = _strlen(a->name) + _strlen(a->value) + 2;
		entry = malloc(sizeof(char) * entry_len);
		_strcpy(entry, a->name);
		entry = _strcat(entry, "=");
		entry = _strcat(entry, a->value);
		str_env[cnt] = entry;
		cnt++;
		a = a->next;
	}
	str_env[cnt] = NULL;
	return (str_env);
}
