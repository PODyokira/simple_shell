
#include "main.h"

/**
 * start_proc - execution of a new process
 * @d: input data structure
 * Return: void
 */

void start_proc(data *d)
{
	pid_t child_pid = fork();
	int status = 0;

	if (child_pid == -1)
		goto free;
	if (child_pid == 0 && execve(d->av[0], d->av, NULL) == -1)
		goto free;
	else if (wait(&status) == -1)
		goto free;
	return;
free:
	perror(d->shell_n);
	free_ary(d->av);
	free(d->cmd);
	exit(EXIT_FAILURE);
}

/**
 * handler_sig - function that handles
 * the SIGINT signal.
 * @signal: the int input
 * Return: void
 */

void handler_sig(int signal)
{
	const char prompt[] = "\n#csisfun$ ";
	(void)signal;
	_printf(prompt);
}

/**
 * _exec - executes cmd
 * @d: input data structure
 * Return: void
 */

void _exec(data *d)
{

	const char prompt[] = "#csisfun$ ";

	signal(SIGINT, handler_sig);

	while (1)
	{
		_printf(prompt);

		r_cmd(d);
		if (_str_len(d->cmd) != 0)
		{
			split(d, " ");
			if (!exec_buil(d))
			{
				_which(d);
				if (access(d->av[0], F_OK) == -1)
				{
					perror(d->shell_n);
				}
				else
				{
					start_proc(d);
				}
			}
		}
		free_ary(d->av);
		free(d->cmd);
	}
}
