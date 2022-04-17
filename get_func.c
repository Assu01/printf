#include "main.h"

/**
 * get_func - look for the specifier.
 *
 * @x: variable to the function.
 *
 * Return: function
 */
int (*get_func(char x))(va_list)
{
	int index = 0;
	spec arr[] = {
		{"c", print_c},
		{"s", print_s},
		{"S", print_s},
		{"%", print_percent},
		{"d", print_d},
		{"i", print_i},
		{"b", print_b},
		{"u", print_u},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{"p", print_p},
		{"r", print_rev},
		{"R", print_R},
		{NULL, NULL}
	};
	while (arr[index].valid)
	{
		if (x == arr[index].valid[0])
			return (arr[index].f);
		index++;
	}
	return (NULL);
}
