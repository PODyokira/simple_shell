#include "main.h"

/**
 * exec_builtin - check if built in and then exec
 * @dt: data struct input
 * Return: 1 if built in, 0 if not
 */
int exec_builtin(data *dt)
{
	builtin builtin[] = {
		{"exit", builtin_exit},
		{"env", builtin_env},
		{"setenv", builtin_setenv},
		{"unsetenv", builtin_unsetenv},
		{"cd", builtin_cd},
		{NULL, NULL},
	};
	int i = 0;

	for (i = 0; builtin[i].cmd; i++)
	{
		if (_strcmp(dt->av[0], builtin[i].cm²) == 0)
		{
			builtin[i].f(dt);
			return (1);
		}
	}
	return (0);
}

/**
 * builtin_exit - exits the shell
 * @dt: data struct input
 * Return: void
 */
void builtin_exit(data *dt)
{
	if (dt->av[1] && _isnumber(dt->av[1]))
		dt->last_exit_status = atoi(dt->av[1]);
	free_array(dt->av);
	free(dt->cmd);
	if (dt->flag_setenv)
		free_array(environ);
	exit(dt->last_exit_status);
}

/**
 * builtin_env - prints the current environment
 * @dt: data struct input
 * Return: void
 */
void builtin_env(data *dt)
{
	int i = 0;

	(void)dt;
	while (environ[i])
	{
		_printf(environ[i]);
		_printf("\n");
		i++;
	}
}
/**
 * builtin_setenv - Initialize a new environment variable,
 * or modify an existing one
 * @dt: data struct input
 * Return: void
 */

void builtin_setenv(data *dt)
{
	(void)dt;
	if (dt->av[1] && dt->av[2])
	{
		if (_setenv(dt, dt->av[1], dt->av[2]) == -1)
		{
			perror("setenv");
		}
	}
}

/**
 * builtin_unsetenv - Remove an environment variable
 * @dt: data struct input
 * Return: void
 */
void builtin_unsetenv(data *dt)
{
	int i, j;
	int len;

	(void)dt;
	if (!dt->av[1] || !getenv(dt->av[1]))
	{
		_perror(dt->shell_name, "variable not found.");
		return;
	}
	len = strlen(dt->av[1]);
	for (i = 0; environ[i]; i++)
		if (strncmp(environ[i], dt->av[1], len) == 0 && environ[i][len] == '=')
			for (j = i; environ[j]; j++)
				environ[j] = environ[j + 1];
}


