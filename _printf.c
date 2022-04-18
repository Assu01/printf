#include "main.h"
#include <stdarg.h>

/**
 * check_specifier - checks if there is a valid format specifier
 * @fmt: possible valid format specifier
 * Return: pointer to valid function or NULL
 */
int (*check_specifier(const char *fmt))(va_list)
{
	int i = 0;
	print_t func[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_di},
		{"i", print_di},
		{NULL, NULL}
	};

	while (func[i].t != NULL && *(func[i].t) != *fmt)
		i++;

	return (func[i].f);
}

/**
 * _printf - function for format printing
 * @format: list of arguments to printing
 * Return: Number of characters to printing
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int (*f)(va_list);
	unsigned int i = 0, j = 0;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			j++;
			i++;
			continue;
		}
		else
		{
			if (format[i + 1] == '%')
			{
				_putchar('%');
				j++;
				i += 2;
				continue;
			}
			else
			{
				f = check_specifier(&format[i + 1]);
				if (f == NULL)
					return (-1);
				i += 2;
				j += f(ap);
				continue;
			}
		}
		i++;
	}
	va_end(ap);
	return (j);
}
