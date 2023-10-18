#ifndef SIMPLE_H
#define SIMPLE_H

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <unistd.h>

void printr(char *becca, int rae);
void task1(void);
void task2(const char *becca);
int mains(void);
void task5(char *becca, size_t size);

#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

/* this just does in one line: free(x); x = NULL; */
#define FREE(x) (x = (free(x), NULL))
#define PROMPT "Ship$ "
/* structs */
/**
  * struct order - struct to contain &&'s and ||'s
  * @n: coded int, 1 = ; , 2 = && , 3 = ||
  * @next: points to the next node
  */
typedef struct order
{
	unsigned int n;
	struct order *next;
} order_t;
/**
  * struct env_list - struct to contain env
  * @name: name of env var
  * @value: value of env var
  * @next: points to the next node
  */
typedef struct env_list
{
	char *name;
	char *value;
	struct env_list *next;
} env_list_t;
int main(__attribute__((unused))int ac, char **av);

/* getline */
int _getline(char **lineptr, size_t *n, FILE *stream);

/* memory helpers */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* string helpers */
int _atoi(char *l);
int _strlen(char *rst);
char *_strdup(char *rst);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *destin, char *source);
char *_strcat(char *destin, char *source);
char *_strtok(char *buffer, const char *delim);
char *_strchr(char *s, char c);
void _puts(char *rst);
void puts_prompt(void);
int _putchar(char c);
void _puts_int(int n);
int MATH_pow(int base, int exp);

/* cmd_handler */
int task13(char **argv, env_list_t **env);
int built_in_handler(char **argv, env_list_t **env, int r);
int _cd(char **argv, env_list_t **env);
void do_something(int something);

/* cmd assembly */
char **fetch_tokens(char *string_tok, char *delim);
int task10(char *trm, char *diy);
char *task6(char *cmd, env_list_t **env);
void comments_r(char *rst);
void task14(char **argv);

/* env variable */
char **_initenv(void);
void _setenv(char **argv, char ***env);
void _unsetenv(char *entry, char ***env);
char *_getenv(char *entry, char ***env);
void _printenv(char ***env);

/* env_list */
env_list_t **_initenvs_list(void);
void printenvs_list(env_list_t **env);
char *_getenv_list_value(char *name, env_list_t **env);
env_list_t *_getenv_l_node(char *name, env_list_t **env);
void _setenv_list(char **argv, env_list_t **env);
void free_env_l_node(env_list_t *node);
void _unsetenv_list(char **argv, env_list_t **env);
void frees_env_list(env_list_t **env);
char **_get_str_env(env_list_t **env);

/* ops */
void *task11(order_t **pso, int n);
char **_get_comands(char *line, order_t **pso);
void free_pso(order_t **pso);

extern char **environ;
extern int *NUM_LINE;
extern char **TASK4_FUNC;

#endif
