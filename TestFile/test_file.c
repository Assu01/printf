#include "main.h"
#include <stdio.h>

int main(void)
{
	int len1, len2;

	len1 = _printf("string working");
	len2 = printf("tested original printf");
	_printf("Length:[%d, %i]\n", len1, len1);
	printf("Length:[%d, %i]\n", len, len);

	return (0);
}
