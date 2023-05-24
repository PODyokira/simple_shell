#include "main.h"

/**
 * _printf - print a string to stander out put
 * @string: string input
 * Return: void
 */
void _printf(const char *string)
{
	if (!string)
		return;
	while (*string)
	{
		write(STDOUT_FILENO, string, 1);
		string++;
	}
}

/**
 * free_array - free an array of pointers
 * @Ary: array of pointers
 * Return: void
 */
void free_Ary(char **Ary)
{
	int i;

	if (!Ary)
		return;

	for (i = 0; Ary[i]; i++)
	{
		free(Ary[i]);
		Ary[i] = NULL;
	}

	free(Ary);
}

/**
 * split - split a given string by a delimiter
 * @dt: data struct input
 * @delim: string input
 * Return: void
 */
void split(data *dt, const char *delim)
{
	char *token;
	int n_token = 0;

	dt->av = malloc(2 * sizeof(char *));
	if (dt->av == NULL)
	{
		free(dt->cmd);
		perror(dt->shell_name);
		exit(EXIT_FAILURE);
	}
	dt->av[0] = NULL;
	dt->av[1] = NULL;

	token = strtok(dt->cmd, delim);
	while (token)
	{
		dt->av = _realloc(dt->av, (n_token + 2) * sizeof(char *));
		if (dt->av == NULL)
			goto free;
		dt->av[n_token] = _strdup(token);
		if (dt->av[n_token] == NULL)
			goto free;
		n_token++;
		token = strtok(NULL, delim);
	}
	dt->av[n_token] = NULL;
	return;
free:
	free_array(dt->av);
	free(dt->cmd);
	perror(dt->shell_name);
	exit(EXIT_FAILURE);
}

/**
 * init_data - init data
 * @dt: data struct input
 * @shell_name: string input
 * Return: void
 */

void init_data(data *dt, const char *shell_name)
{
	dt->cmd = NULL;
	dt->av = NULL;
	dt->shell_name = shell_name;
	dt->last_exit_status = EXIT_SUCCESS;
	dt->flag_setenv = 0;
}

/**
 * read_cmd - get the commend from the prompt and structure it into data struct
 * @dt: data struct input
 * Return: void
 */
void read_cmd(data *dt)
{
	size_t n = 0;
	ssize_t n_read;
	int i = 0;

	n_read = _getline(&dt->cmd, &n, stdin);

	if (n_read == -1)
	{
		free(dt->cmd);
		exit(EXIT_SUCCESS);
	}

	dt->cmd[n_read - 1] = '\0';
	_trim(d->cmd);

	for (i = 0; dt->cmd[i] != '\0'; i++)
	{
		if (dt->cmd[i] == '#')
		{
			dt->cmd[i] = '\0';
			break;
		}
	}
	_trim(dt->cmd);
}

