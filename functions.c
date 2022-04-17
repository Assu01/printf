#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_c - Prints character.
 *
 * @args: Character argument.
 *
 * Return: Number of character.
 */
int print_c(va_list args)
{
	int ch;

	ch = va_arg(args, int);

	return (_putchar(ch));
}

/**
 * print_s - Prints a string.
 *
 * @args: String argument.
 *
 * Return: Number of characters.
 */
int print_s(va_list args)
{
	int index = 0, count = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	while (str[index] != '\0')
	{
		_putchar(str[index]);
		index++;
		count++;
	}

	return (count);
}

/**
 * print_percent - pass the percent sing
 *
 * @args: String argument.
 *
 * Return: The percent sing.
 */
int print_percent(va_list args)
{
	char *str;

	str = "%";

	if (va_arg(args, int) == *str)
	{
		return (*str);
	}

	return (*str);
}

/**
 * print_d - Prints a decimal.
 *
 * @args: Decimal argument.
 *
 * Return: counter.
 */
int print_d(va_list args)
{
	unsigned int absolute, aux, numcount = 1, count;
	int num;

	count = 0;

	num = va_arg(args, int);

	if (num < 0)
	{
		absolute = (num * (-1));
		count += _putchar('-');
	}
	else
		absolute = num;

	aux = absolute;

	while (aux > 9)
	{
		aux /= 10;
		numcount *= 10;
	}

	while (numcount >= 1)
	{
		count += _putchar(((absolute / numcount) % 10) + '0');
		numcount /= 10;
	}

	return (count);
}

/**
 * print_i - Prints integer.
 *
 * @args: Integer argument.
 *
 * Return: The decimal funcion.
 */
int print_i(va_list args)
{
	return (print_d(args));
}
