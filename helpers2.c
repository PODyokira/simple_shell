
#include "main.h"

/**
 * _perror - print in std error
 * @str1: name for the shell program
 * @str2: the message error
 * Return: void
 */
void _perror(const char *str1, const char *str2)
{
	if (!str1 || !str2)
		return;

	while (*str1)
	{
		write(stder_fil, str1, 1);
		str1++;
	}

	write(stder_fil, ": ", 2);

	while (*str2)
	{
		write(stder_fil, str2, 1);
		str2++;
	}
	write(stder_fil, "\n", 1);
}


/**
 * _trim - remove trailing white spaces
 * and tabs from a string.
 * @str: the string input
 * Return: void
 */

void _trim(char *str)
{
	int i, j, len = _str_len(str);

	for (i = 0; i < len && (str[i] == ' ' || str[i] == '\t'); i++)
		;

	for (j = 0; i < len ; i++, j++)
		str[j] = str[i];

	str[j] = '\0';

	for (i = _str_len(str) - 1; i > 0 && (str[i] == ' ' || str[i] == '\t'); i--)
		str[i] = '\0';
}


/**
 * _realloc - a function that reallocates
 * memory blocks using malloc and free
 * @ptr: a void pointez
 * @n_size: an unsigned int
 * Return: the new allocated memory
 */
void *_realloc(void *ptr, unsigned int n_size)
{
	char *p;
	unsigned int i, tp = n_size, o_size = sizeof(ptr);

	if (o_size == n_size)
		return (ptr);
	if (ptr == NULL)
		return (malloc(n_size));

	if (n_size > o_size)
		tp = o_size;

	if (n_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	p = malloc(n_size);

	for (i = 0; i < tp; i++)
		p[i] = ((char *)ptr)[i];
	free(ptr);
	return (p);
}
