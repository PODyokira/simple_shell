
#include "main.h"

/**
 * _str_len - function that returns the
 * number of characters in a given string.
 * @str: the string input
 * Return: number of chars in the given string.
 */

unsigned int _str_len(char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}


/**
 * _str_cmp - function that compares two strings
 * and returns an integer.
 * @s1: input const string
 * @s2: input const string
 * Return: returns an integer indicating the result of
 * the string comparison, with the following conventions:
 * 0 if s1 == s2
 * A negative value if s1 < s2
 * A positive value if s1 > s2"
 */
int _str_cmp(const char *s1, const char *s2)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	return (res);
}

/**
 * _str_ncmp - function that compares two strings
 * @s1: input const string
 * @s2: input const string
 * @n: input int
 * Return: returns an integer indicating the result of the
 * comparison, with the following conventions:
 * 0 if s1 == s2
 * A negative value if s1 < s2
 * A positive value if s1 > s2"
 */
int _str_ncmp(const char *s1, const char *s2, int n)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{

		if (i >= n)
			break;
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	return (res);
}

/**
 * _str_cpy - function that copies the contents of the
 * source string to the destination string
 * @dest: input char *
 * @src: input const char *
 * Return: char *
 */
char *_str_cpy(char *dest, const char *src)
{
	int len;

	for (len = 0; src[len] != '\0'; ++len)
	{
		dest[len] = src[len];
	}
	dest[len] = '\0';
	return (dest);
}

/**
 * _str_cat - function that appends the source
 * string to the destination string.
 * @dest: input string
 * @src: input const string
 * Return: void
 */
char *_str_cat(char *dest, const char *src)
{
	char *result = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (result);
}
