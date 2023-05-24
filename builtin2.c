#include "main.h"

/**
 * builtin_cd - change directory
 * @dt: data struct input
 * Return: void
 */
void builtin_cd(data *dt)
{
	char *dir = dt->av[1];
	char cwd[256];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		perror("getcwd() error");
	_setenv(dt, "PWD", cwd);
	if (!dir)
		dir = _getenv("HOME");
	if (chdir(dir) == -1)
		perror("cd");
	else
	{
		_setenv(dt, "OLDPWD", _getenv("PWD"));
		if (getcwd(cwd, sizeof(cwd)) == NULL)
			perror("getcwd() error");
		_setenv(dt, "PWD", cwd);
	}
}

