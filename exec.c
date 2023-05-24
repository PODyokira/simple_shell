#include "main.h"

/**
 * start_process - start a new process
 * @dt: data struct input
 * Return: void
 */

void start_process(data *dt)
{
	pid_t child_pid = fork();
	int status = 0;

	if (child_pid == -1)
		goto free;
	if (child_pid == 0 && execve(dt->av[0], dt->av, NULL) == -1)
		goto free;
	else if (wait(&status) == -1)
		goto free;
	if (WIFEXITED(status))
		dt->last_exit_status = WEXITSTATUS(status);
	return;
free:
	perror(dt->shell_name);
	free_array(dt->av);
	free(dt->cmd);
	exit(EXIT_FAILURE);
}

/**
 * handler_sigint - sig handler function
 * @sig: int input
 * Return: void
 */

void handler_sigint(int sig)
{
	/*const char prompt[] = PROMPT;*/
	(void)sig;
	exit(EXIT_FAILURE);
	/*_printf(prompt);*/
}

/**
 * _exec - exectute cmd
 * @dt: data struct input
 * Return: void
 */

void _exec(data *dt)
{
	const char prompt[] = PROMPT;

	sig(SIGINT, handler_sigint);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_printf(prompt);

		read_cmd(dt);
		if (_strlen(dt->cmd) != 0)
		{
			split(dt, " ");
			if (!exec_builtin(d))
			{
				_which(dt);
				if (access(dt->av[0], F_OK) == -1)
				{
					perror(dt->shell_name);
				}
				else
				{
					start_process(dt);
				}
			}
			free_array(dt->av);
		}
		free(dt->cmd);
	}
}

