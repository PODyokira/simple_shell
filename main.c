#include "main.h"

/**
 * main - init data
 * @arg_c: input size of @arg_v
 * @arg_v: input array of command line arguments
 * Return: Always 0.
 */
int main(int arg_c, char **arg_v)
{
	data dt;
	(void)arg_c;
	init_data(&dt, arg_v[0]);
	_exec(&dt);

	return (0);
}

