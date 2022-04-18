#include "main.h"

/**
 * get_func - returns key function
 * @i: identifier
 * Return: pointer to key fey functions
 */
char* (*get_func(char i))(va_list)
{
	int k = 0;

	print keys[] = {
		{'c', print_char},
		{'s', print_str},
		{'d', print_dec},
		{'i', print_dec},
		{'o', print_octal},
		{'b', itob},
		{'r', print_rev},
		{'R', rot13},
		{'\0', NULL}
	};

	while (keys[k].id != '\0')
	{
		if (keys[k].id == i)
			return (keys[k].func);
		k++;
	}
	return (NULL);
}
/**
 * create_buffer - creates buffer to hold string until it's ready for print
 * Return: pointer to buffer created
 */
char *create_buffer(void)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return (NULL);
	return (buffer);
}

/**
 * write_buffer - prints buffer, then frees it and frees va_list
 * @buffer: buffer holding print-ables
 * @len: length of print-able string
 * @list: va_list
 */
void write_buffer(char *buffer, int len, va_list list)
{
	char *buff;

	buff = realloc(buffer, len);
	write(1, buff, len);

	free(buff);
	va_end(list);
}
