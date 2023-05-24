#include "main.h"

/**
 * _getline_helper - getline helper function
 * @line_ptr: string input
 * @n: int input
 * Return: int
 */
int _getline_helper(char **line_ptr, size_t *n)
{
	if (*line_ptr == NULL || *n == 0)
	{
		*n = 128;
		*line_ptr = malloc(*n);
		if (*line_ptr == NULL)
			return (-1);
	}
	return (0);
}

/**
 * _getline - reads the input from FILE
 * @line_ptr: string input
 * @n: int input
 * @stream: FILE input
 * Return: ssize_t
 */
ssize_t _getline(char **line_ptr, size_t *n, FILE *stream)
{
	ssize_t bytes_read = 0;
	size_t pos = 0, new_size;
	static char buff[READ_buff_SIZE];
	static size_t buff_size, buff_pos;
	char *new_buff;

	if (line_ptr == NULL || n == NULL || stream == NULL
		|| _getline_helper(line_ptr, n) == -1)
		return (-1);
	while (1)
	{
		if (buff_pos >= buff_size)
		{
			bytes_read = read(stream->_fileno, buff, READ_buff_SIZE);
			if (bytes_read <= 0 && pos == 0)
				return (-1);
			else if (bytes_read <= 0)
				break;
			buff_size = bytes_read;
			buff_pos = 0;
		}
		if (pos >= *n - 1)
		{
			new_size = *n * 2;
			new_buff = realloc(*line_ptr, new_size);
			if (new_buff == NULL)
				return (-1);
			*line_ptr = new_buff;
			*n = new_size;
		}
		(*line_ptr)[pos++] = buff[buff_pos++];
		if ((*line_ptr)[pos - 1] == '\n')
			break;
	}
	(*line_ptr)[pos] = '\0';
	return (pos);
}

