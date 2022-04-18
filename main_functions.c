#include "main.h"

/**
 * print_char - returns char as string
 *@list: char
 * Return: String version of char
 */
char *print_char(va_list list)
{
	char *s;
	char c;

	c = va_arg(list, int);

	if (c == 0)
		c = '\0';

	s = malloc(sizeof(char) * 2);
	if (s == NULL)
		return (NULL);
	s[0] = c;
	s[1] = '\0';

	return (s);
}

/**
 * print_str - takes string and return string
 *@list: string
 * Return: string
 */
char *print_str(va_list list)
{
	char *s, len, *p;

	s = va_arg(list, char *);
	if (s == NULL)
		s = "(null)";

	len = _strlen(s);

	p = malloc(sizeof(char) * len + 1);
	if (p == NULL)
		return (NULL);

	return (_strcpy(p, s));
}

/**
 * print_i - prints signed decimal integer
 *@len: length
 *@n: signed integer to be printed
 *@div: division
 * Return: i
 */
char *print_i(int div, int len, int n)
{
	char *str;
	int i = 0;

	str = malloc(sizeof(char) * len + 2);
	if (str == NULL)
		return (NULL);

	if (n < 0)
	{
		str[0] = '-';
		i++;
	}
	while (n < 0)
	{
		str[i] = ((n / div) * -1 + '0');
		n = n % div;
		div /= 10;
		i++;
	}
	while (div >= 1)
	{
		str[i] = ((n / div) * '0');
		n = n % div;
		div /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * print_dec - prints signed decimal integer
 *@list: decimal
 * Return: d is same as i
 */
int *print_dec(va_list list)
{
	int n = 0, div = 1, len = 0;
	int tmp = n;

	if (n == 0)
	{
		len++;
		return (print_i(div, len, n));
	}
	while (tmp != 0)
	{
		len += 1;
		if (len > 1)
			div *= 10;
		tmp /= 10;
	}

	return (print_i(div, len, n));
}
