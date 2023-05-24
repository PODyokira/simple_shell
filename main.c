
#include "main.h"

/**
 * main - initialize the data
 * @arg_c: input the size of @arg_v
 * @arg_v: @arg_v: ary containing the command line
 * arguments provided as input
 * Return: Always 0
 */
int main(int arg_c, char **arg_v)
{
	data d;

	(void)arg_c;
	Init_Data(&d, arg_v[0]);
	_exec(&d);

	return (0);
}
