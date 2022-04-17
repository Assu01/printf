#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_b - Custom conversion specifiers unsigned to binary.
 *
 * @args: The number of arguments.
 *
 * Return: The unsigned int argument is converted to binary.
 */
int print_b(va_list args)
{
	int count = 0, index = 1, retval;
	unsigned int deciNum = va_arg(args, unsigned int);
	char *str;

	if (deciNum < 1)
	{
		_putchar(0 + '0');

		return (1);
	}

	count += countBinary(deciNum);
	str = malloc(sizeof(char) * (count + 1));

	if (str == NULL)
		return (-1);

	for (; index < (count + 1); index++)
	{
		str[count - index] = deciNum % 2;
		deciNum = deciNum / 2;
	}

	for (index = 0; index < count; index++)
	{
		retval = _putchar(str[index] + '0');

		if (retval == -1)
		{
			free(str);

			return (-1);
		}
	}

	free(str);

	return (count);
}

/**
 * print_u - Prints unsigned int.
 *
 * @args: The number of arguments
 *
 * Return: The number specified by u.
 */
int print_u(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int digits = num;
	int count = 0, retval;

	if (num < 1)
	{
		_putchar('0');

		return (1);
	}

	retval = print_number(num);

	if (retval == 1)
		count += countDigits(digits);
	else
		count = -1;

	return (count);
}

/**
 * print_o - Prints octal num from decimal.
 *
 * @args: The number of arguments.
 *
 * Return: The speciefer of o.
 */
int print_o(va_list args)
{
	unsigned int deciNum = va_arg(args, unsigned int), remainder;
	int count = 0, index = 1, retval;
	char *str;

	count += countOctal(deciNum);
	str = malloc(sizeof(char) * (count + 1));

	if (str == NULL)
		return (-1);

	for (; index < (count + 1); index++)
	{
		remainder = deciNum % 8;
		deciNum = deciNum / 8;
		str[count - index] = remainder + '0';
	}

	for (index = 0; index < count; index++)
	{
		retval = _putchar(str[index]);

		if (retval == -1)
		{
			free(str);

			return (-1);
		}
	}

	free(str);
	return (count);
}

/**
 * print_pointer - Convert and print an unsigned long int in hex.
 *
 * @ptr: The address of the pointer to print.
 * @count: The number of bytes printed.
 *
 * Return: void.
 */
void print_pointer(unsigned long ptr, int *count)
{
	int retVal;

	if (ptr > 15)
		print_pointer(ptr >> 4, count);

	if (*count == -1)
		return;

	if ((ptr & 15) < 10)
		retVal = _putchar('0' + (ptr & 15));
	else
		retVal = _putchar('a' + (ptr & 15) % 10);

	if (retVal == -1)
		*count = -1;
	else
		*count += retVal;
}

/**
 * print_p - Prints a pointer address in lowercase hexdci.
 *
 * @args: va_list cointaining the pointer as the next element
 *
 * Return: The number of bytes printed
 */
int print_p(va_list args)
{
	int count = 0;
	void *ptr = va_arg(args, void *);

	if (!ptr)
		return (_printf("(nil)"));

	count = _printf("0x");

	if (count == -1)
		return (count);

	print_pointer((unsigned long)ptr, &count);

	return (count);
}
