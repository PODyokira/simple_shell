
#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

extern char **env;

/**
 * struct data - a data structure that
 * holds the main data
 * @av: Token ary to be passed as arguments
 * for the execve function
 * @cmd: command line
 * @shell_n: The name for the shell program.
 */
typedef struct data
{
	char **av;
	char *cmd;
	const char *shell_n;
} data;

/**
 * struct builtin - data structure that holds
 * the primary data
 * @cmd: integrated cmd
 * @f: function of integrated cmd
 */
typedef struct builtin
{
	const char *cmd;
	void (*f)(data *d);
} builtin;

int exec_buil(data *d);
void built_exist(data *d);
void built_env(data *d);

void _printf(const char *str);
void free_ary(char **ary);
void split(data *d, const char *delim);
void Init_Data(data *d, const char *shell_n);
void r_cmd(data *d);

void _perror(const char *str1, const char *str2);
void _trim(char *str);
void *_realloc(void *ptr, unsigned int n_size);

void start_proc(data *d);
void handler_sig(int sig);
void _exec(data *d);

char *_getenv(char *name);
int _which(data *d);

unsigned int _str_len(char *str);
int _str_cmp(const char *s1, const char *s2);
int _str_ncmp(const char *s1, const char *s2, int n);
char *_str_cpy(char *dest, const char *src);
char *_str_cat(char *dest, const char *src);

char *_str_dup(const char *str);

ssize_t _get_line(char **lineP, size_t *n, FILE *stream);


