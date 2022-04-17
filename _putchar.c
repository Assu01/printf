#include <unistd.h>

/**
 * _putchar - Write a character.
 *
 * @c: The character to be printed.
 *
 * Return: 1(Success) -1(Fail)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
