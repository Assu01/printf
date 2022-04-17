#include "main.h"
#include <stdlib.h>

/**
 * print_R - prints the rot13'ed string.
 *
 * @args: Arguments of strings to be encoded with rot13.
 *
 * Return: Nuumber of characters to be printed.
 */
int print_R(va_list args)
{
	char *str = va_arg(args, char *), *encoded = NULL;
	char *rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	int index = 0, count = 0;

	encoded = malloc(sizeof(char) * (_strlen(str) + 1));

	if (!encoded || !str)
		return (-1);

	for (; str[count]; count++)
	{
		for (; index < 52; index++)
		{
			if (str[count] == alpha[index])
			{
				encoded[count] = rot13[index];

				break;
			}
		}

		if (str[count] != alpha[index])
			encoded[count] = str[count];
	}

	for (count = 0; encoded[count]; count++)
		_putchar(encoded[count]);

	free(encoded);

	return (count);
}
