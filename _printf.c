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

void cleanup(va_list args, buffer_t *output);
int run_printf(const char *format, va_list args, buffer_t *output);
int _printf(const char *format, ...);

/**
 * cleanup - Peforms cleanup operations for _printf.
 * @args: A va_list of arguments provided to _printf.
 * @output: A buffer_t struct.
 */
void cleanup(va_list args, buffer_t *output)
{
	va_end(args);
	write(1, output->start, output->len);
	free_buffer(output);
}

/**
 * run_printf - Reads through the format string for _printf.
 * @format: Character string to print - may contain directives.
 * @output: A buffer_t struct containing a buffer.
 * @args: A va_list of arguments.
 *
 * Return: The number of characters stored to output.
 */
int run_printf(const char *format, va_list args, buffer_t *output)
{
	int i, wid, prec, ret = 0;
	char tmp;
	unsigned char flags, len;
	unsigned int (*f)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);

	for (i = 0; *(format + i); i++)
	{
		len = 0;
		if (*(format + i) == '%')
		{
			tmp = 0;
			flags = handle_flags(format + i + 1, &tmp);
			wid = handle_width(args, format + i + tmp + 1, &tmp);
			prec = handle_precision(args, format + i + tmp + 1,
					&tmp);
			len = handle_length(format + i + tmp + 1, &tmp);

			f = handle_specifiers(format + i + tmp + 1);
			if (f != NULL)
			{
				i += tmp + 1;
				ret += f(args, output, flags, wid, prec, len);
				continue;
			}
			else if (*(format + i + tmp + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}
		ret += _memcpy(output, (format + i), 1);
		i += (len != 0) ? 1 : 0;
	}
	cleanup(args, output);
	return (ret);
}

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list args;
	int ret;

	if (format == NULL)
		return (-1);
	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(args, format);

	ret = run_printf(format, args, output);

	return (ret);
}
