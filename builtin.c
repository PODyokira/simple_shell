
#include "main.h"

/**
 * exec_buil - a function that verifies if a command is a
 * built-in command and executes it accordingly.
 * @d: input data structure
 * Return: 1 if the command is a built-in command, 0 if not.
 */
int exec_buil(data *d)
{
	builtin builtin[] = {
		{"exit", built_exist},
		{"env", built_env},
		{NULL, NULL},
	};
	int i = 0;

	for (i = 0; builtin[i].cmd; i++)
	{
		if (_str_cmp(d->av[0], builtin[i].cmd) == 0)
		{
			builtin[i].f(d);
			return (1);
		}
	}
	return (0);
}

/**
 * built_exist - exit the shell
 * @d: input data structure
 * Return: void
 */
void built_exist(data *d)
{
	int status = 0;

	if (d->av[1])
		status = atoi(d->av[1]);
	free_ary(d->av);
	free(d->cmd);
	exit(status);
}

/**
 * built_env - function that prints the
 * current envment
 * @d: input data structure
 * Return: void
 */
void built_env(data *d)
{
	int i = 0;

	(void)d;
	while (env[i])
	{
		_printf(env[i]);
		_printf("\n");
		i++;
	}
}
