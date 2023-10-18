#include "simple.h"

/**
  * _cd - change directory
  * @argv: argument vector
  * @env: environment linked list
  */
int _cd(char **argv, env_list_t **env)
{
	char buffer[BUFSIZ]; /* BUFSIZ is predefined~8k */
	char *home = _getenv_list_value("HOME", env);
	char *old = _getenv_list_value("OLDPWD", env);
	char **OLDPWD = malloc(sizeof(char *) * 4);
	char **PWD = malloc(sizeof(char *) * 4);
	DIR *diy;

	OLDPWD[0] = "";
	OLDPWD[1] = "OLDPWD";
	OLDPWD[2] = buffer;
	OLDPWD[3] = NULL;
	PWD[0] = "";
	PWD[1] = "PWD";
	PWD[2] = buffer;
	PWD[3] = NULL;
	getcwd(buffer, sizeof(buffer));
	if (argv[1])
	{
		diy = opendir(argv[1]);
		if (diy)
		{
			closedir(diy);
			chdir(argv[1]);
		}
		else if (!_strcmp(argv[1], "~"))
			chdir(home);
		else if (!_strcmp(argv[1], "-"))
		{
			if (!old)
			{
				_puts(*TASK4_FUNC);
				_puts(": ");
				_puts_int(*NUM_LINE);
				_puts(": can't cd to ");
				_puts(argv[1]);
				_putchar('\n');
				free(OLDPWD);
				free(PWD);
				return (1);
			}
			else
				chdir(old);
		}
		else
		{
			_puts(*TASK4_FUNC);
			_puts(": ");
			_puts_int(*NUM_LINE);
			_puts(": can't cd to ");
			_puts(argv[1]);
			_putchar('\n');
			free(OLDPWD);
			free(PWD);
			return (1);
		}
	}
	else
		chdir(home);
	_setenv_list(OLDPWD, env);
	getcwd(buffer, sizeof(buffer));
	_setenv_list(PWD, env);
	free(OLDPWD);
	free(PWD);
	return (0);
}
