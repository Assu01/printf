#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
/**
 * struct specifier - struct specifier.
 *
 * @valid: The valid character.
 * @f: The functions associated.
 */

typedef struct specifier
{
	char *valid;
	int (*f)(va_list);
} spec;

int _putchar(char c);
int (*get_func(char x))(va_list args);
int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_d(va_list args);
int print_i(va_list args);
int print_percent(va_list args);
int print_b(va_list args);
int print_u(va_list args);
int print_o(va_list args);
int print_p(va_list args);
int print_rev(va_list args);
int print_R(va_list args);
void print_pointer(unsigned long ptr, int *count);
int print_x(va_list args);
void print_lowerHex(unsigned int num, int *count);
int print_X(va_list args);
void print_upperHex(unsigned int num, int *count);
int countDigits(unsigned int num);
int countOctal(unsigned int num);
int countBinary(unsigned int num);
int print_number(unsigned int n);
int _strlen(char *);
#endif
