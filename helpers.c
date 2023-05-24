
#include "main.h"

/**
 * _printf - prints a string to stdout
 * @str: the string input
 * Return: void
 */
void _printf(const char *str)
{
	if (!str)
		return;
	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
}

/**
 * free_ary - function to deallocates memory for
 * an array of pointers
 * @array: the array of pointers
 * Return: void.
 */

void free_ary(char **array)
{
	int i;

	if (!array)
		return;

	for (i = 0; array[i]; i++)
		free(array[i]);

	free(array);
}

/**
 * split - function that divides a given
 * string into multiple substrings
 * @d: input data structure
 * @delim: the string input
 * Return: void.
 */

void split(data *d, const char *delim)
{
	char *token;
	int n_token = 0;

	d->av = malloc(2 * sizeof(char *));
	if (d->av == NULL)
	{
		free(d->cmd);
		perror(d->shell_n);
		exit(EXIT_FAILURE);
	}
	d->av[0] = NULL;
	d->av[1] = NULL;

	token = strtok(d->cmd, delim);
	while (token)
	{
		d->av = _realloc(d->av, (n_token + 2) * sizeof(char *));
		if (d->av == NULL)
			goto free;
		d->av[n_token] = _str_dup(token);
		if (d->av[n_token] == NULL)
			goto free;
		n_token++;
		token = strtok(NULL, delim);
	}
	d->av[n_token] = NULL;
	return;
free:
	free_ary(d->av);
	free(d->cmd);
	perror(d->shell_n);
	exit(EXIT_FAILURE);
}

/**
 * Init_Data - initilize the data
 * @d: inpute data structure
 * @shell_n: the string input
 * Return: void
 */

void Init_Data(data *d, const char *shell_n)
{
	d->cmd = NULL;
	d->av = NULL;
	d->shell_n = shell_n;
}

/**
 * r_cmd - function that retrieves the command
 * from the prompt and organizes it into
 * a data structure.
 * @d: the data structure input
 * Return: void
 */

void r_cmd(data *d)
{
	size_t n = 0;
	ssize_t n_read;

	n_read = _get_line(&d->cmd, &n, stdin);

	if (n_read == -1)
	{
		free(d->cmd);
		exit(EXIT_FAILURE);
	}

	d->cmd[n_read - 1] = '\0';
	_trim(d->cmd);
}
