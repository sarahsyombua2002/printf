#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: format string 
 * Description: this function will call the get_print() function that will
 *
 * Return: length of the formatted output string
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += write(1, &va_arg(args, int),1);
					break;
				case 's':
					count += prrintf("%s", va_arg(args, char*));
					break;
				case '%':
					count += putchar('%');
					break;
				default:
					putchar('%');
					putchar(*format);
					count += 2;
				}
		}
		else
		{
			putchar(*formar);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
