#include "main.h"

/**
 * print_rev - print the reversed string
 * @list: holds values
 *
 * Return: reversed string
 */
char *print_rev(va_list list)
{
	char *rev, *str;
	int len, i = 0, j;

	str = va_arg(list, char *);
		if (str == NULL)
			str = "(NULL)";

	len = _strlen(str);

	rev = malloc(sizeof(char) * len + 1);
	if (rev == NULL)
		return (NULL);

	for(j = (len - 1); j > 0; j--)
	{
		rev[i++] = str[j];
	}

	rev[i] = '\0';
	return (rev);

}
