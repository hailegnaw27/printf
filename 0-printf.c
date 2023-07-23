#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Prints output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                int c = va_arg(args, int);
                count += write(1, &c, 1);
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                int len = 0;
                
                while (str[len])
                    len++;
                
                count += write(1, str, len);
            }
            else if (*format == '%')
            {
                count += write(1, "%", 1);
            }
        }
        else
        {
            count += write(1, format, 1);
        }

        format++;
    }

    va_end(args);

    return count;
}

