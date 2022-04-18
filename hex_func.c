#include "main.h"

/**
 * print_hex_base - base function for printing hexadecimal numbers
 * @list: argument list containing hexadecimal
 * @_case: a in caps on lower, printing the hex number in caps in lower
 * Return: number of digits printed
 */
char *print_hex_base(va_list list, char _case)
{
	unsigned int num = va_list(list, unsigned int);
	int nbrCharacters;

	if (num == 0)
		return (_putchar('0'));
	nbrCharacters = print_unsignedIntToHex(num, _case);

	return (nbrCharacters);
}

/**
 * print_hex - Prints a hexidecimal in lowercase
 * @list: list that contains hexadecimal to print
 * Return: number of digits printed
 */
char *print_hex(va_list list)
{
	return (print_hex_base(list, 'a'));
}

/**
 * print_HEX - Prints a hexadecimal in uppercase
 * @list: list of arguments passed into the function
 * Return: number of characters printed
 */

char *print_HEX(va_list list)
{
	return (print_hex_base(list, 'A'));
}
