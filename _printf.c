#include "main.h"
/**
 * _printf - prints anything (output) according to a format
 * @format: character string (c, s, %)
 * Return: numbers of characters printed.
 */

int _printf(const char *format, ...)
{
	va_list list;
	int i = 0, index = 0, count = 0, (*gof)(va_list list);

	va_start(list, format);

	if ((format == NULL) || (format[0] == '%' && format[1] == '\0'))
	return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
	index = i + 1;
	if (format[i] != '%')
	{
	_putchar(format[i]);
	count++;
	}
	else if (format[i] == '%' && format[index] == '%')
	{
	_putchar('%');
	i = index;
	count++;
	}
	else
	{
	gof = get_op_func(&format[index]);
	if (gof != NULL)
	{
	count += gof(list);
	i = index;
	}
	else
	{
	_putchar(format[i]);
	count++;
	}
	}
	}
	va_end(list);
	return (count);
}

/**
 * op_char - Function that prints char
 *
 * @list: Variable type va_list
 *
 *Return: 0
 *
 */
int op_char(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}

/**
 * op_string - Function that prints string
 *
 * @list: Variable type va_list
 * collaborative task by Thulani Moko and Thandiwe Khalaki
 *Return: 0
 *
 */
int op_string(va_list list)
{
	char *s = va_arg(list, char*);
	int count = 0;

	if (s == NULL)
	s = "(null)";

	while (*s != '\0')
	{
	_putchar(*s);
	s++;
	count++;
	}

	return (count);
}

/**
 * op_integer - Function that prints integer or decimal
 *
 * @list: Variable type va_list
 *
 *Return: 0
 *
 */
int op_integer(va_list list)
{
	int number = va_arg(list, int);
	unsigned int positive = 0;
	int count = 0;

	if (number < 0)
	{
	_putchar('-');
	count++;
	positive = number * (-1);
	}
	else
	{
	positive = number;
	}

	count += fnc_put_number_recursion(positive);

	return (count);
}

/**
 * fnc_put_number_recursion - Function that prints the numbers with recursion
 * @number: Variable unsigned int type
 * Return: Count to the numbers prints
 */
int fnc_put_number_recursion(unsigned int number)
{
	unsigned int r_mod, r_div;
	int count = 0;

	r_mod = number % 10;
	r_div = number / 10;

	if (r_div != 0)
	{
	count += (fnc_put_number_recursion(r_div));
	count++;
	_putchar(r_mod + '0');
	}
	else
	{
	_putchar(number + '0');
	count++;
	}

	return (count);
}
