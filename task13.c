#include "simple.h"
/**
  * built_in_handler - handles built in fncs
  * @argv: argument vector
  * @env: environment linked list
  * @i: switch for built-ins
  */
int built_in_handler(char **argv, env_list_t **env, int r)
{
	switch (r)
	{
		case 0:
			return(_cd(argv, env));
		case 1:
			_setenv_list(argv, env);
			break;
		case 2:
			_unsetenv_list(argv, env);
			break;
		case 3:
			printenv_list(env);
			break;
	}
	return (0);
}
/**
  * task13 - handles all commands
  * @argv: argument vector
  * @env: environment linked list
  * Return: 0 on failure, 1 on true
  */
int task13(char **argv, env_list_t **env)
{
	char *built_ins[] = {"cd", "setenv", "unsetenv", "env", NULL};
	int r, status, exit_value = 0;
	struct stat st;
	char *path_file = NULL;
	pid_t child_process;
	char **str_env = _get_str_env(env);
	
	for (r = 0; built_ins[r]; r++)
	{
		if (!_strcmp(built_ins[r], argv[0]))
		{
			exit_value = built_in_handler(argv, env, r);
			task14(str_env);
			return (exit_value);
		}
	}
	if (stat(argv[0], &st) == 0)
		path_file = argv[0];
	else
	{
		path_file = task6(argv[0], env);
		if (path_file)
		{
			path_file = _strcat(path_file, "/");
			path_file = _strcat(path_file, argv[0]);
		}
	}
	if (!path_file)
	{
		_puts(*TASK4_FUNC);
		_puts(": ");
		_puts_int(*NUM_LINE);
		_puts(": ");
		_puts(argv[0]);
		_puts(" not found\n");
		task14(str_env);
		return (127);
	}
	child_process = fork();
	if (child_process == -1)
	{
		perror("Error:");
		return (0);
	}
	if (child_process == 0)
	{
		if (execve(path_file, argv, str_env) == -1)
			perror("Error:");
		exit(0);
	}
	wait(&status);
	exit_value = WEXITSTATUS(status);
	task14(str_env);
	return (exit_value);
}
