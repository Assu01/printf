#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * _printf - Recreates the printf function.
 *
 * @format: String with format specifier.
 * @...: The number of arguments.
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	if (format != NULL)
	{
		int count = 0, index = 0;
		int (*variadic)(va_list);
		va_list args;

		va_start(args, format);
		if (format[0] == '%' && format[1] == '\0')
			return (-1);
		while (format != NULL && format[index] != '\0')
		{
			if (format[index] == '%')
			{
				if (format[index + 1] == '%')
				{
					count += _putchar(format[index]);
					index += 2;
				}
				else
				{
					variadic = get_func(format[index + 1]);
					if (variadic)
						count += variadic(args);
					else
						count = _putchar(format[index]) + _putchar(format[index + 1]);
					index += 2;
				}
			}
			else
			{
				count += _putchar(format[index]);
				index++;
			}
		}
		va_end(args);
		return (count);
	}
	return (-1);
}
