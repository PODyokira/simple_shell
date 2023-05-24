
#include "main.h"

/**
 * _getenv - retrieves the value of an envment variable.
 * @name: the string input
 * Return: value of the envment variable.
 */

char *_getenv(char *name)
{
	int i = -1;
	size_t name_len;

	if (name == NULL || *name == '\0')
		return (NULL);
	if (env == NULL)
		return (NULL);

	name_len = _str_len(name);

	while (env[++i])
	{
		if (!_str_ncmp(env[i], name, name_len) && env[i][name_len] == '=')
		{
			return (env[i] + name_len + 1);
		}
	}
	return (NULL);
}

/**
 * _which - a function that identifies the exe file
 * associated with a given command.
 * @d: the string input
 * Return: void.
 */
int _which(data *d)
{
	char *token, *path,
		*paths = malloc(_str_len(_getenv("PATH") ? _getenv("PATH") : "") + 1);
	size_t token_len;
	int find = -1;

	if (!_getenv("PATH"))
		goto step_out;
	_str_cpy(paths, _getenv("PATH"));
	if (paths == NULL)
		goto step_out;
	token = strtok(paths, ":");
	while (token)
	{
		token_len = _str_len(token) + _str_len(d->av[0]) + 2;
		path = malloc(token_len);
		if (path == NULL)
			return (find);
		_str_cpy(path, token);
		_str_cat(path, "/");
		_str_cat(path,  d->av[0]);
		if (access(path, F_OK) == 0)
		{
			free(d->av[0]);
			d->av[0] = _str_dup(path);
			free(path);
			find = 0;
			break;
		}
		free(path);
		token = strtok(NULL, ":");
	}
step_out:
	free(paths);
	return (find);
}
