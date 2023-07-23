#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_octal - Prints an unsigned integer in octal format
 * @num: The unsigned integer to be printed
 * @count: A pointer to the count of printed characters
 */
void print_octal(unsigned int num, int *count)
{
	if (num / 8)
		print_octal(num / 8, count);

	*count += _putchar((num % 8) + '0');
}

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char ch;

	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'o':
					print_octal(va_arg(args, unsigned int), &count);
					break;

				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			ch = *format;
			_putchar(ch);
			count++;
		}

		format++;
	}

	va_end(args);

	return (count);
}

