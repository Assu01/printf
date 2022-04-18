#ifndef MAIN_H
#define MAIN_H

/* needed header files for printf */
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* given prototype for printf */
int _printf(const char *format, ...);

/* external prototype functions */
int *print_char(va_list list);
char *print_str(va_list list);
int *print_dec(va_list list);
char *print_octal(va_list list);
char* (*get_func(char i))(va_list);
char *print_rev(va_list list);
char *itob(va_list list);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *rot13(va_list list);
char *create_buffer(void);
void write_buffer(char *buffer, int len, va_list list);

/**
 * struct types - struct function
 * @id: struct identifier
 * @func: pointer to function
 */

typedef struct types
{
	char id;
	char* (*func)(va_list);
} print;

#endif
