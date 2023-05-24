#include "main.h"

/**
 * _get_line_h - function for getline helper
 * @lineP: string input
 * @n: int input
 * Return: int
 */
int _get_line_h(char **lineP, size_t *n)
{
	if (*lineP == NULL || *n == 0)
	{
		*n = 128;
		*lineP = malloc(*n);
		if (*lineP == NULL)
			return (-1);
	}
	return (0);
}

/**
 * _get_line - function that read the input from FILE
 * @lineP: the string input
 * @n: int input
 * @stream: FILE input
 * Return: ssize_t
 */
ssize_t _get_line(char **lineP, size_t *n, FILE *stream)
{
	ssize_t bytes_read = 0;
	size_t pos = 0, newsize;
	static char buf[READ_BUF_SIZE];
	static size_t bfsize, bfpos;
	char *newbuf;

	if (lineP == NULL || n == NULL || stream == NULL
		|| _get_line_h(lineP, n) == -1)
		return (-1);
	while (1)
	{
		if (bfpos >= bfsize)
		{
			bytes_read = read(stream->_fileno, buf, READ_BUF_SIZE);
			if (bytes_read <= 0 && pos == 0)
				return (-1);
			else if (bytes_read <= 0)
				break;
			bfsize = bytes_read;
			bfpos = 0;
		}
		if (pos >= *n - 1)
		{
			newsize = *n * 2;
			newbuf = realloc(*lineP, newsize);
			if (newbuf == NULL)
				return (-1);
			*lineP = newbuf;
			*n = newsize;
		}
		(*lineP)[pos++] = buf[bfpos++];
		if ((*lineP)[pos - 1] == '\n')
			break;
	}
	(*lineP)[pos] = '\0';
	return (pos);
}
