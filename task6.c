#include "shell.h"

/**
  * task6 - locates cmd's in the PATH
  * @rmd: char * containing the cmd
  * @env_l_j: is the name of the environment
  * @env: environment linked list
  * Return: as mentioned
  */
char *task6(char *rmd, env_l_j **env)
{
	char *PATH = _getenv_list_value("PATH", env);
	char *PATH_COPY;
	static char buffer[256];
	char **toks;
	int r;

	if (!PATH)
		return (NULL);
	PATH_COPY = _strdup(PATH);
	toks = fetch_tokens(PATH_COPY, ":");

	for (r = 0; toks[r]; r++)
	{
		if (isin_dir(cmd, toks[r]))
		{
			buffer[0] = 0;
			_strcat(buffer, toks[r]);
			FREE(PATH_COPY);
			free(toks);
			return (buffer);
		}
	}
	FREE(PATH_COPY);
	free(toks);
	return (NULL);
}
