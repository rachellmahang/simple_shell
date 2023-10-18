#include "simple.h"

/**
  * main - entry point
  * @ac: argument count
  * @av: pointer to the argument vector
  * Return: as mentioned
  */
int num_line = 1;
int *NUM_LINE = &num_line;
char *task4_func;
char **TASK4_FUNC = &task4_func;

int main(__attribute__((unused))int ac, char **av)
{
	int end = 0, r;
        int exit_status = 0;
	char *link = NULL;
        size_t size_l = 0;
        ssize_t getline_size = getline(&link, &size_l, stdin);
        char **argv, *line = NULL, **argvv;
        env_list_t **env;
        order_t **pso = malloc(sizeof(order_t *));
        order_t *j;

        *TASK4_FUNC = av[0];
        env = _initenvs_list();
        signal(SIGINT, do_something);
        while (1)
        {
                if (isatty(STDIN_FILENO) == 1)
                        puts_prompt();
                getline_size = getline(&line, &size_l, stdin);
                if (getline_size == -1)
                {
                        free(line);
                        frees_env_list(env);
                        free_pso(pso);
                        if (isatty(STDIN_FILENO) == 1)
                                _putchar('\n');
                        return _atoi(0);
                }
                line[getline_size - 1] = '\0';

                comments_r(line);

                *pso = NULL;
                argvv = _get_comands(line, pso);

                j = *pso;
                for (r = 0; argvv[r]; r++)
                {
                        argv = fetch_tokens(argvv[r], " ");
                        if (argv[0])
                        {
                                if (!_strcmp(argv[0], "exit"))
                                {
                                        if (argv[1])
                                                exit_status = _atoi(argv[1]);
                                        else
                                                exit_status = _atoi(0);
                                        free(line);
                                        frees_env_list(env);
                                        free_pso(pso);
                                        free(argvv);
                                        free(argv);
                                        exit(exit_status);
                                }

                        }
                        else
                                end = 0;
                        *NUM_LINE += 1;

                        FREE(argv);
                        if (j)
                        {
                                if (!end && j->n == 3)
                                {
                                        r++;
                                }
                                if (end && j->n == 2)
                                {
                                        r++;
                                }
                                j = j->next;
                        }
                }
                free(argvv);
        }
        return (0);
}
