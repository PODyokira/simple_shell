#ifndef MAIN_H
#define MAIN_H


#define PROMPT "#csisfun$ "

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <sig.h>

extern char **environ;

/**
 * struct data - holds the main data.
 * @av: Array of tokens to pass for execve
 * @cmd: The user input, the command line
 * @shell_name: The name of the shell program
 * @last_exit_status: last exit status of last command executed
 * @flag_setenv: 1 if user did exec setenv (use it to free memory)
 */
typedef struct data
{
	char **av;
	char *cmd;
	const char *shell_name;
	int last_exit_status;
	int flag_setenv;
} data;

/**
 * struct builtin - holds the main data.
 * @cmd: built in cmd
 * @fb: function of builtin cmd
 */
typedef struct builtin
{
	const char *cmd;
	void (*fb)(data *dt);
} builtin;

/* builtin.c */
int exec_builtin(data *dt);
void builtin_exit(data *dt);
void builtin_env(data *dt);
void builtin_setenv(data *dt);
void builtin_unsetenv(data *dt);
void builtin_cd(data *dt);


/* helpers.c */
void _printf(const char *str);
void free_array(char **Ary);
void split(data *dt, const char *delim);
void init_data(data *dt, const char *shell_name);
void read_cmd(data *dt);

/* helpers2.c */
void _perror(const char *st1, const char *st2);
void _trim(char *str);
void *_realloc(void *pp, unsigned int new_size);

/* exec.c */
void start_process(data *dt);
void handler_sigint(int sig);
void _exec(data *dt);

/* path.c */
char *_getenv(char *name);
int _which(data *dt);
int _setenv(data *dt, char *name, char *value);

/* string_utils.c */
unsigned int _strlen(char *str);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, int n);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);


/* string_utils2.c */
char *_strdup(const char *str);
int _isnumber(const char *status);
int _isdigit(int c);

/* _getline.c */
#define READ_buff_SIZE 1024

ssize_t _getline(char **line_ptr, size_t *n, FILE *stream);


#endif

